module.exports = grammar({
  name: 'tree',

  externals: $ => [
    $._indent,
    $._dedent,
    $._newline,
  ],

  conflicts: $ => [
    [$.list_item],
  ],

  rules: {
    document: $ => repeat($._list_item_or_empty_line),

    _list_item_or_empty_line: $ => choice(
      $.list_item,
      $._newline
    ),

    list_item: $ => seq(
      $.list_marker,
      $.list_item_content,
      optional(seq($._newline, optional($.list)))
    ),

    list_marker: $ => '-',

    list_item_content: $ => /[^\n]+/,

    list: $ => seq(
      $._indent,
      repeat1($._list_item_or_empty_line),
      $._dedent
    ),
  }
});
