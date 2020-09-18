%{
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "y.tab.h"    
int yywrap();
void yyerror (char *s);
int yylex();
%}


%%
display                         { return DISPLAY; }
float                           { yylval.s = strdup(yytext) ; return  FLOAT; }
'if'                            { return IF; }
[a-zA-Z]+                       { yylval.s = strdup(yytext) ; return VARNAME; } 
[0-9]+(\.[0-9]+)?([eE][0-9]+)?  { yylval.f = atof(yytext); return FNUM; }
[+\-*/)(=;]                      { return yytext[0]; }
[ \t\n]                         { ; }
.                               { ECHO; yyerror ("unexpected character"); } 
%%

int yywrap(){
    return 1;
}

