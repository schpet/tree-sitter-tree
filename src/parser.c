#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 20
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 10
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  sym_content = 1,
  sym__indent = 2,
  sym__dedent = 3,
  sym__newline = 4,
  sym_document = 5,
  sym__list_item_or_empty_line = 6,
  sym_list_item = 7,
  sym_children = 8,
  aux_sym_document_repeat1 = 9,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_content] = "content",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym__newline] = "_newline",
  [sym_document] = "document",
  [sym__list_item_or_empty_line] = "_list_item_or_empty_line",
  [sym_list_item] = "list_item",
  [sym_children] = "children",
  [aux_sym_document_repeat1] = "document_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_content] = sym_content,
  [sym__indent] = sym__indent,
  [sym__dedent] = sym__dedent,
  [sym__newline] = sym__newline,
  [sym_document] = sym_document,
  [sym__list_item_or_empty_line] = sym__list_item_or_empty_line,
  [sym_list_item] = sym_list_item,
  [sym_children] = sym_children,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_content] = {
    .visible = true,
    .named = true,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym__dedent] = {
    .visible = false,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym__list_item_or_empty_line] = {
    .visible = false,
    .named = true,
  },
  [sym_list_item] = {
    .visible = true,
    .named = true,
  },
  [sym_children] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_children = 1,
  field_content = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_children] = "children",
  [field_content] = "content",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_content, 0},
  [1] =
    {field_children, 1},
    {field_content, 0},
  [3] =
    {field_children, 2},
    {field_content, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 3,
  [6] = 4,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 7,
  [11] = 9,
  [12] = 8,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 13,
  [17] = 14,
  [18] = 15,
  [19] = 19,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(1);
      if (lookahead == '\n') SKIP(0);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(sym_content);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(3);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(sym_content);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 3},
  [5] = {.lex_state = 0, .external_lex_state = 3},
  [6] = {.lex_state = 0, .external_lex_state = 3},
  [7] = {.lex_state = 0, .external_lex_state = 4},
  [8] = {.lex_state = 0, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 4},
  [10] = {.lex_state = 0, .external_lex_state = 1},
  [11] = {.lex_state = 0, .external_lex_state = 1},
  [12] = {.lex_state = 0, .external_lex_state = 2},
  [13] = {.lex_state = 0, .external_lex_state = 2},
  [14] = {.lex_state = 0, .external_lex_state = 2},
  [15] = {.lex_state = 0, .external_lex_state = 2},
  [16] = {.lex_state = 0, .external_lex_state = 3},
  [17] = {.lex_state = 0, .external_lex_state = 3},
  [18] = {.lex_state = 0, .external_lex_state = 3},
  [19] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_content] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(19),
    [sym__list_item_or_empty_line] = STATE(2),
    [sym_list_item] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_content] = ACTIONS(5),
    [sym__newline] = ACTIONS(7),
  },
  [2] = {
    [sym__list_item_or_empty_line] = STATE(3),
    [sym_list_item] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_content] = ACTIONS(5),
    [sym__newline] = ACTIONS(11),
  },
  [3] = {
    [sym__list_item_or_empty_line] = STATE(3),
    [sym_list_item] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_content] = ACTIONS(15),
    [sym__newline] = ACTIONS(18),
  },
  [4] = {
    [sym__list_item_or_empty_line] = STATE(5),
    [sym_list_item] = STATE(5),
    [aux_sym_document_repeat1] = STATE(5),
    [sym_content] = ACTIONS(21),
    [sym__dedent] = ACTIONS(23),
    [sym__newline] = ACTIONS(25),
  },
  [5] = {
    [sym__list_item_or_empty_line] = STATE(5),
    [sym_list_item] = STATE(5),
    [aux_sym_document_repeat1] = STATE(5),
    [sym_content] = ACTIONS(27),
    [sym__dedent] = ACTIONS(13),
    [sym__newline] = ACTIONS(30),
  },
  [6] = {
    [sym__list_item_or_empty_line] = STATE(5),
    [sym_list_item] = STATE(5),
    [aux_sym_document_repeat1] = STATE(5),
    [sym_content] = ACTIONS(21),
    [sym__dedent] = ACTIONS(33),
    [sym__newline] = ACTIONS(25),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(37), 1,
      sym__indent,
    ACTIONS(39), 1,
      sym__newline,
    STATE(13), 1,
      sym_children,
    ACTIONS(35), 2,
      ts_builtin_sym_end,
      sym_content,
  [14] = 3,
    ACTIONS(21), 1,
      sym_content,
    ACTIONS(42), 1,
      sym__newline,
    STATE(4), 3,
      sym__list_item_or_empty_line,
      sym_list_item,
      aux_sym_document_repeat1,
  [26] = 3,
    ACTIONS(37), 1,
      sym__indent,
    STATE(14), 1,
      sym_children,
    ACTIONS(44), 3,
      sym__newline,
      ts_builtin_sym_end,
      sym_content,
  [38] = 4,
    ACTIONS(46), 1,
      sym__indent,
    ACTIONS(48), 1,
      sym__newline,
    STATE(16), 1,
      sym_children,
    ACTIONS(35), 2,
      sym__dedent,
      sym_content,
  [52] = 3,
    ACTIONS(46), 1,
      sym__indent,
    STATE(17), 1,
      sym_children,
    ACTIONS(44), 3,
      sym__dedent,
      sym__newline,
      sym_content,
  [64] = 3,
    ACTIONS(21), 1,
      sym_content,
    ACTIONS(51), 1,
      sym__newline,
    STATE(6), 3,
      sym__list_item_or_empty_line,
      sym_list_item,
      aux_sym_document_repeat1,
  [76] = 1,
    ACTIONS(53), 3,
      sym__newline,
      ts_builtin_sym_end,
      sym_content,
  [82] = 1,
    ACTIONS(55), 3,
      sym__newline,
      ts_builtin_sym_end,
      sym_content,
  [88] = 1,
    ACTIONS(57), 3,
      sym__newline,
      ts_builtin_sym_end,
      sym_content,
  [94] = 1,
    ACTIONS(53), 3,
      sym__dedent,
      sym__newline,
      sym_content,
  [100] = 1,
    ACTIONS(55), 3,
      sym__dedent,
      sym__newline,
      sym_content,
  [106] = 1,
    ACTIONS(57), 3,
      sym__dedent,
      sym__newline,
      sym_content,
  [112] = 1,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 14,
  [SMALL_STATE(9)] = 26,
  [SMALL_STATE(10)] = 38,
  [SMALL_STATE(11)] = 52,
  [SMALL_STATE(12)] = 64,
  [SMALL_STATE(13)] = 76,
  [SMALL_STATE(14)] = 82,
  [SMALL_STATE(15)] = 88,
  [SMALL_STATE(16)] = 94,
  [SMALL_STATE(17)] = 100,
  [SMALL_STATE(18)] = 106,
  [SMALL_STATE(19)] = 112,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [30] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 1, 0, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_list_item, 1, 0, 1), SHIFT(9),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 2, 0, 1),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_list_item, 1, 0, 1), SHIFT(11),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 2, 0, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 3, 0, 3),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_children, 3, 1, 0),
  [59] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__indent = 0,
  ts_external_token__dedent = 1,
  ts_external_token__newline = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__indent] = sym__indent,
  [ts_external_token__dedent] = sym__dedent,
  [ts_external_token__newline] = sym__newline,
};

static const bool ts_external_scanner_states[5][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token__newline] = true,
  },
  [2] = {
    [ts_external_token__newline] = true,
  },
  [3] = {
    [ts_external_token__dedent] = true,
    [ts_external_token__newline] = true,
  },
  [4] = {
    [ts_external_token__indent] = true,
    [ts_external_token__newline] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_tree_external_scanner_create(void);
void tree_sitter_tree_external_scanner_destroy(void *);
bool tree_sitter_tree_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_tree_external_scanner_serialize(void *, char *);
void tree_sitter_tree_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_tree(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_tree_external_scanner_create,
      tree_sitter_tree_external_scanner_destroy,
      tree_sitter_tree_external_scanner_scan,
      tree_sitter_tree_external_scanner_serialize,
      tree_sitter_tree_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
