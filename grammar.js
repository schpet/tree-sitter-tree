const PREC = {
  INDENT: 1,
  DEDENT: 1,
};

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
      field('content', $.content),
      optional($._newline),
      optional(field('children', $.children))
    ),

    content: $ => /[^\n]+/,

    children: $ => prec.dynamic(PREC.INDENT, seq(
      $._indent,
      repeat1($._list_item_or_empty_line),
      $._dedent
    )),
  }
});
