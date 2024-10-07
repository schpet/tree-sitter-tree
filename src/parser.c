#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 20
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 11
#define ALIAS_COUNT 0
#define TOKEN_COUNT 6
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_list_marker = 1,
  sym_list_item_content = 2,
  sym__indent = 3,
  sym__dedent = 4,
  sym__newline = 5,
  sym_document = 6,
  sym__list_item_or_empty_line = 7,
  sym_list_item = 8,
  sym_list = 9,
  aux_sym_document_repeat1 = 10,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_list_marker] = "list_marker",
  [sym_list_item_content] = "list_item_content",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym__newline] = "_newline",
  [sym_document] = "document",
  [sym__list_item_or_empty_line] = "_list_item_or_empty_line",
  [sym_list_item] = "list_item",
  [sym_list] = "list",
  [aux_sym_document_repeat1] = "document_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_list_marker] = sym_list_marker,
  [sym_list_item_content] = sym_list_item_content,
  [sym__indent] = sym__indent,
  [sym__dedent] = sym__dedent,
  [sym__newline] = sym__newline,
  [sym_document] = sym_document,
  [sym__list_item_or_empty_line] = sym__list_item_or_empty_line,
  [sym_list_item] = sym_list_item,
  [sym_list] = sym_list,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_list_marker] = {
    .visible = true,
    .named = true,
  },
  [sym_list_item_content] = {
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
  [sym_list] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
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
  [9] = 7,
  [10] = 8,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 11,
  [15] = 12,
  [16] = 13,
  [17] = 17,
  [18] = 18,
  [19] = 17,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(2);
      if (lookahead == '-') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(sym_list_marker);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(sym_list_item_content);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(5);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(sym_list_item_content);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(5);
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
  [9] = {.lex_state = 0, .external_lex_state = 1},
  [10] = {.lex_state = 0, .external_lex_state = 2},
  [11] = {.lex_state = 0, .external_lex_state = 2},
  [12] = {.lex_state = 0, .external_lex_state = 2},
  [13] = {.lex_state = 0, .external_lex_state = 2},
  [14] = {.lex_state = 0, .external_lex_state = 3},
  [15] = {.lex_state = 0, .external_lex_state = 3},
  [16] = {.lex_state = 0, .external_lex_state = 3},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_list_marker] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(18),
    [sym__list_item_or_empty_line] = STATE(2),
    [sym_list_item] = STATE(2),
    [aux_sym_document_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_list_marker] = ACTIONS(5),
    [sym__newline] = ACTIONS(7),
  },
  [2] = {
    [sym__list_item_or_empty_line] = STATE(3),
    [sym_list_item] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_list_marker] = ACTIONS(5),
    [sym__newline] = ACTIONS(11),
  },
  [3] = {
    [sym__list_item_or_empty_line] = STATE(3),
    [sym_list_item] = STATE(3),
    [aux_sym_document_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_list_marker] = ACTIONS(15),
    [sym__newline] = ACTIONS(18),
  },
  [4] = {
    [sym__list_item_or_empty_line] = STATE(5),
    [sym_list_item] = STATE(5),
    [aux_sym_document_repeat1] = STATE(5),
    [sym_list_marker] = ACTIONS(21),
    [sym__dedent] = ACTIONS(23),
    [sym__newline] = ACTIONS(25),
  },
  [5] = {
    [sym__list_item_or_empty_line] = STATE(5),
    [sym_list_item] = STATE(5),
    [aux_sym_document_repeat1] = STATE(5),
    [sym_list_marker] = ACTIONS(27),
    [sym__dedent] = ACTIONS(13),
    [sym__newline] = ACTIONS(30),
  },
  [6] = {
    [sym__list_item_or_empty_line] = STATE(5),
    [sym_list_item] = STATE(5),
    [aux_sym_document_repeat1] = STATE(5),
    [sym_list_marker] = ACTIONS(21),
    [sym__dedent] = ACTIONS(33),
    [sym__newline] = ACTIONS(25),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(37), 1,
      sym__indent,
    STATE(12), 1,
      sym_list,
    ACTIONS(35), 3,
      sym__newline,
      ts_builtin_sym_end,
      sym_list_marker,
  [12] = 3,
    ACTIONS(21), 1,
      sym_list_marker,
    ACTIONS(39), 1,
      sym__newline,
    STATE(4), 3,
      sym__list_item_or_empty_line,
      sym_list_item,
      aux_sym_document_repeat1,
  [24] = 3,
    ACTIONS(41), 1,
      sym__indent,
    STATE(15), 1,
      sym_list,
    ACTIONS(35), 3,
      sym__dedent,
      sym__newline,
      sym_list_marker,
  [36] = 3,
    ACTIONS(21), 1,
      sym_list_marker,
    ACTIONS(43), 1,
      sym__newline,
    STATE(6), 3,
      sym__list_item_or_empty_line,
      sym_list_item,
      aux_sym_document_repeat1,
  [48] = 2,
    ACTIONS(47), 1,
      sym__newline,
    ACTIONS(45), 2,
      ts_builtin_sym_end,
      sym_list_marker,
  [56] = 1,
    ACTIONS(50), 3,
      sym__newline,
      ts_builtin_sym_end,
      sym_list_marker,
  [62] = 1,
    ACTIONS(52), 3,
      sym__newline,
      ts_builtin_sym_end,
      sym_list_marker,
  [68] = 2,
    ACTIONS(54), 1,
      sym__newline,
    ACTIONS(45), 2,
      sym__dedent,
      sym_list_marker,
  [76] = 1,
    ACTIONS(50), 3,
      sym__dedent,
      sym__newline,
      sym_list_marker,
  [82] = 1,
    ACTIONS(52), 3,
      sym__dedent,
      sym__newline,
      sym_list_marker,
  [88] = 1,
    ACTIONS(57), 1,
      sym_list_item_content,
  [92] = 1,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
  [96] = 1,
    ACTIONS(61), 1,
      sym_list_item_content,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 12,
  [SMALL_STATE(9)] = 24,
  [SMALL_STATE(10)] = 36,
  [SMALL_STATE(11)] = 48,
  [SMALL_STATE(12)] = 56,
  [SMALL_STATE(13)] = 62,
  [SMALL_STATE(14)] = 68,
  [SMALL_STATE(15)] = 76,
  [SMALL_STATE(16)] = 82,
  [SMALL_STATE(17)] = 88,
  [SMALL_STATE(18)] = 92,
  [SMALL_STATE(19)] = 96,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [30] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 3, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 2, 0, 0),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_list_item, 2, 0, 0), SHIFT(7),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_item, 4, 0, 0),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 3, 0, 0),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_list_item, 2, 0, 0), SHIFT(9),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [59] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
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
