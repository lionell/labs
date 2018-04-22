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
$ sed -i 's/\<FIELD\>/LCHILD/g' lchild.l lchild.y
$ sed -i 's/\<BYTES\>/PTR/g' lchild.l lchild.y
$ sed -i 's/\<START\>/PAIR/g' lchild.l lchild.y
$ sed -i 's/\<TYPE\>/RULES/g' lchild.l lchild.y
```

## Add new attributes

First of all let's add these to `lex`. This is fairly simple, just copy any rule like `RULES` and rename it to what you need. In my case I added 2 rules right after `RULES` rule
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

Now we have to make `yacc` aware of our new attributes. To do this we have to add them to token and type sections. We can replace old list with a new one like this
```
$ sed -i 's/NAME PTR PAIR RULES/NAME PTR PAIR RULES INDEX RKSIZE/g' lchild.y
```

Finally, we have to add new grammar rule for each attribute added. We can just copy any rule and rename it. For `LCHILD` I added 2 rules right after `RULES`
```
|	INDEX'='TERM		{ $$ = new ParserExpression("INDEX", $3, NULL, true); }
|	RKSIZE'='TERM		{ $$ = new ParserExpression("RKSIZE", $3, NULL, true); }
```
