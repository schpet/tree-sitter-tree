parses plain text lists.

rules:

- lines without any relative indentation are new list items
- indenting a following line by 2 spaces continues the previous line
- indenting a line 4 spaces makes it a child of the previous list items
- tabs are not supported
