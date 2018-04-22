# Tutorial

How to get `LCHILD` parser from `FIELD` parser. First of all let's look at attribute grammar.
```
field::=  "FIELD"

                [ "NAME"  "="  field-name     => key-value
                | "BYTES" "="  field-bytes    => key-value
                | "START" "="  field-start    => key-value
                | "TYPE"  "="  field-type     => key-value
                | ","
                ] + ""    field-eline:*eol* => symbol

lchild::= "LCHILD"

                [ "NAME"    "="  lchild-name     => key-value
                | "POINTER" "="  lchild-pointer  => key-value
                | "PAIR"    "="  lchild-pair     => key-value
                | "RULES"   "="  lchild-rules    => key-value
                | "INDEX"   "="  lchild-index    => key-value
                | "RKSIZE"  "="  lchild-rksize   => key-value
                | ","
                ] + ""   lchild-eline:*eol* =>symbol
```

We are going to just replace all attributes from `FIELD` with ones from `LCHILD` and add new if needed.

## Replace attributes

You can do this using `sed` tool like this
```
$ sed -i 's/FIELD/LCHILD/g' lchild.l lchild.y
$ sed -i 's/BYTES/PTR/g' lchild.l lchild.y
$ sed -i 's/START/PAIR/g' lchild.l lchild.y
$ sed -i 's/TYPE/RULES/g' lchild.l lchild.y
```

## Add new attributes

First of all let's add these to `lex`. This is fairly simple, just copy any rule like `TYPE` and rename it to what you need. In my case I added 2 rules
```
INDEX {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
    return INDEX;
}
RKSIZE {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
    return RKSIZE;
}
```
