%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"    
int yywrap();
void yyerror (char *s);
int yylex();
%}


%%

[0-9]+(\.[0-9]+)?([eE][0-9]+)? { yylval.f = atof(yytext); return FNUM;}
[-+()*/;]                       {return yytext[0];}
[ \t\n]                        {;}
.                              {ECHO; yyerror ("unexpected character");} 

%%

int yywrap(){
    return 1;
}

