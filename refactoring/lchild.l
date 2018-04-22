%{
    #include <string>
    #define YYSTYPE std::string
    #include "lchild.tab.hpp"
    void yyerror(char *s);
    
    char m_invalidEscape[] = "Invalid escape sequence";
    char m_newline[] = "Newline in string literal";
    char m_invalidCharacter[] = "Invalid character";
    
    
    int offset = 0;
    int startOfPunchedCard = 79;
    
%}

%option yylineno
%option noyywrap


%x STR

%%

LCHILD {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
    return LCHILD;
    }
NAME {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
   return NAME;
}
PTR {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
    return PTR;
}
PAIR {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
    return PAIR;
}
RULES {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
    return RULES;
}
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
PUNCHEDCARD {
    return PUNCHEDCARD;
}


[0-9]+          {
    yylval = yytext;
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    } else {
        return NUM;
    }
//    if (yyleng == 8)
//    return PUNCHEDCARD;
//    else

}
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval = yytext;
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
    
    return ID;
}
<STR>[^\\\n"]+  {

        ///*
        
        for (int i = 0; i < yyleng; i++) {
            yytext[i] = ' ';
        }
        BEGIN 0;
        //*/
        
        ///*
            //strncat(yyval, yytext, 72);
        //*/
        
        yylval += yytext;
}

<STR>\\n        yylval += '\n';
<STR>\\         yyerror(m_invalidEscape);
<STR>\n         {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }

    for (int i = 0; i < yyleng; i++) {
    yytext[i] = ' ';
    }
    BEGIN 0;
    //yyerror(m_newline);
}
[ \t\r\n]       {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
}; // whitespace
[-{};()<>=+*/!,] {
    offset += yyleng;
    if (offset > startOfPunchedCard) {
        BEGIN STR;
    }
    return *yytext;
}
.               yyerror(m_invalidCharacter);

%%
