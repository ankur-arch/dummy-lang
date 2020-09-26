%{
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Types.h"
#include "y.tab.h"    
int yywrap();
void yyerror (char *s);
int yylex();
%}


%%
","                             { return yytext[0]; }
"<"                             { return yytext[0]; } 
">"                             { return yytext[0]; }
"--"                            { return DECR; }
"++"                            { return INCR; }
"+="                            { return PLUSASSIGN;  }
"-="                            { return MINUSASSIGN; }
"*="                            { return MULASSIGN;   }
"/="                            { return DIVASSIGN;   }
"%="                            { return MODASSIGN;   }
"if"                            { yylval.s = strdup(yytext) ; return IF;}
"else"                          { yylval.s = strdup(yytext) ; return ELSE;}
"else if"                       { yylval.s = strdup(yytext) ; return ELSEIF;}
"}"                             { return yytext[0]; }                                
"{"                             { return yytext[0]; }        
"<="                            { return LTE; } 
">="                            { return GTE; } 
"=="                            { return EQ; }
"!="                            { return NET; }
"!"                             { return NOT; }  
"&&"                            { return AND; }
"||"                            { return OR; }    
display                         { return DISPLAY; }
return                          { return RETURN ; }   
float                           { yylval.s = strdup(yytext) ; return  FLOAT; }
int                           { yylval.s = strdup(yytext) ; return  INT; }
void                           { yylval.s = strdup(yytext) ; return  VOID; }
'if'                            { return IF; }
[a-zA-Z]+                       { yylval.s = strdup(yytext) ; return VARNAME; } 
[0-9]+(\.[0-9]+)?([eE][0-9]+)?  { yylval.f = atof(yytext); return FNUM; }
[+\-*/)(=%;]                      { return yytext[0]; }
[ \t\n]+                         { ; }
.                               { ECHO; yyerror ("unexpected character"); } 
%%

int yywrap(){
    return 1;
}

