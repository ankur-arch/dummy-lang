%{
#include<stdio.h>
#include<stdlib.h>
#include "Types.h"
extern int yylex();
int FloatVariableStackCounter = 0;    
void yyerror(char *msg);
%}

%union{
   float f;
   int i;
   char* s;
}

%start M
%token<s> FLOAT
%token<s> VARNAME
%token<f> FNUM
%token LT GT LTE GTE ET EQ NOT NET AND OR IF DISPLAY
%type<s> S 
%type<f> E F G L



%%
M : S ';'       {;}              
  | M S ';'     {;}
  | M DISPLAY E ';' { printf("%f \n",$3); }

S : FLOAT VARNAME '=' E         { struct Float v; v.Name = $2 ; v.Type = $1 ; v.value=$4; addFloatVariable(v); }
  | VARNAME '=' E               { updateFloatVariable($1,$3); }                               
  ;

E : E '+' F     {$$ = $1 + $3;}
  | E '-' F     {$$ = $1 - $3;}
  | F           {$$ = $1;}
  ;

F : F '*' G     {$$ = $1 * $3;} 
  | F '/' G     {$$ = $1/$3;}
  | G           {$$ = $1;}
  ;

G : '(' E ')'   {$$ = ($2);}    
  | '-' G       {$$ = -$2;}
  | L           {$$=$1;} 
  ;

L : FNUM        {$$ = $1;}
  | VARNAME     {$$ = getFloatVariableValue($1); }
  ;    
%%

void yyerror(char *msg){
    fprintf(stderr,"%s\n",msg);
    exit(1);
}

int main(){
    for(int x=0 ; x< 99 ; x++){
      FloatVariableTable[x].Name = "";
      FloatVariableTable[x].Type = "Float";
      FloatVariableTable[x].value = 0.0;
    };
    yyparse();
    return 0;
}
