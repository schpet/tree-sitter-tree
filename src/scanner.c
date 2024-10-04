#include <tree_sitter/parser.h>
#include <string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void *tree_sitter_tree_external_scanner_create();
void tree_sitter_tree_external_scanner_destroy(void *payload);
bool tree_sitter_tree_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols);
unsigned tree_sitter_tree_external_scanner_serialize(void *payload, char *buffer);
void tree_sitter_tree_external_scanner_deserialize(void *payload, const char *buffer, unsigned length);

#ifdef __cplusplus
}
#endif

enum TokenType {
  INDENT,
  DEDENT,
  NEWLINE,
};

typedef struct {
  uint16_t *indent_stack;
  uint32_t indent_stack_size;
  uint32_t indent_stack_capacity;
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static unsigned serialize(Scanner *scanner, char *buffer) {
  if (scanner->indent_stack_size > TREE_SITTER_SERIALIZATION_BUFFER_SIZE / sizeof(uint16_t)) {
    return 0;
  }
  memcpy(buffer, scanner->indent_stack, scanner->indent_stack_size * sizeof(uint16_t));
  return scanner->indent_stack_size * sizeof(uint16_t);
}

static void deserialize(Scanner *scanner, const char *buffer, unsigned length) {
  scanner->indent_stack_size = length / sizeof(uint16_t);
  if (scanner->indent_stack_size > scanner->indent_stack_capacity) {
    free(scanner->indent_stack);
    scanner->indent_stack_capacity = scanner->indent_stack_size;
    scanner->indent_stack = malloc(scanner->indent_stack_capacity * sizeof(uint16_t));
  }
  memcpy(scanner->indent_stack, buffer, length);
}

void *tree_sitter_tree_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->indent_stack_capacity = 32;
  scanner->indent_stack = malloc(scanner->indent_stack_capacity * sizeof(uint16_t));
  scanner->indent_stack_size = 0;
  return scanner;
}

void tree_sitter_tree_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  if (scanner) {
    if (scanner->indent_stack) free(scanner->indent_stack);
    free(scanner);
  }
}

bool tree_sitter_tree_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;

  if (valid_symbols[NEWLINE] && lexer->lookahead == '\n') {
    advance(lexer);
    lexer->result_symbol = NEWLINE;
    return true;
  }

  if (lexer->get_column(lexer) == 0) {
    uint32_t indent_length = 0;
    while (lexer->lookahead == ' ') {
      indent_length++;
      advance(lexer);
    }

    if (lexer->lookahead == '\n') return false;

    if (scanner->indent_stack_size == 0 || indent_length > scanner->indent_stack[scanner->indent_stack_size - 1]) {
      if (valid_symbols[INDENT]) {
        if (scanner->indent_stack_size == scanner->indent_stack_capacity) {
          scanner->indent_stack_capacity *= 2;
          scanner->indent_stack = realloc(scanner->indent_stack, scanner->indent_stack_capacity * sizeof(uint16_t));
        }
        scanner->indent_stack[scanner->indent_stack_size++] = indent_length;
        lexer->result_symbol = INDENT;
        return true;
      }
    } else if (indent_length < scanner->indent_stack[scanner->indent_stack_size - 1]) {
      if (valid_symbols[DEDENT]) {
        scanner->indent_stack_size--;
        lexer->result_symbol = DEDENT;
        return true;
      }
    }
  }

  return false;
}

unsigned tree_sitter_tree_external_scanner_serialize(void *payload, char *buffer) {
  Scanner *scanner = (Scanner *)payload;
  return serialize(scanner, buffer);
}

void tree_sitter_tree_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  Scanner *scanner = (Scanner *)payload;
  deserialize(scanner, buffer, length);
}
