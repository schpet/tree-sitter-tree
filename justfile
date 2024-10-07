default: generate build test

aider:
    aider grammar.js src/scanner.c test/corpus/*

test: generate
    tree-sitter test

generate:
    tree-sitter generate

build:
    tree-sitter build

playground: generate
    tree-sitter build --wasm
    tree-sitter playground

examples-basic:
    -tree-sitter parse examples/basic.tree.txt

examples-multiline:
    -tree-sitter parse examples/multiline.tree.txt
