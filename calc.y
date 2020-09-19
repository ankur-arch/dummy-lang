%{
#include<stdio.h>
#include<stdbool.h>
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
%token '<' '>' LTE GTE EQ NOT NET AND OR IF DISPLAY
%type<s> S 
%type<f> E F L D 
%type<f> G CONDITION


%left GTE LTE EQ NET '>' '<'
%left NOT AND OR

%%
M : S ';'       {;}
  | CONDITION ';'       {;}        
  | M S ';'     {;}
  | M DISPLAY E ';' { printf("%f \n",$3); }
  | M CONDITION ';'     {;}

CONDITION : CONDITION OR CONDITION  {  int result = $1 || $3 ; printf("expression %d \n", result); $$ = $1 || $3; }
          | CONDITION AND CONDITION {  int result = $1 && $3 ; printf("expression %d \n", result); $$ = $1 && $3; }
          | NOT CONDITION           {  int result = $2 == 0 ? 1 : 0 ; printf("expression %d \n", result); $$ = ($2 == 0 ? 1 : 0) ; } 
          | G                                         

G : G '<' G   { printf("hit "); int result = $1 < $3 ; printf("%d \n", result); $$ = (int)($1 < $3); }
  | G '>' G   { printf("hit ");  int result = $1 > $3 ; printf("%d \n", result); $$ = $1 > $3; }
  | G GTE G   { printf("hit ");  int result = $1 >= $3 ; printf("%d \n", result); $$ = $1 >= $3; }
  | G LTE G   { printf("hit ");  int result = $1 <= $3 ; printf("%d \n", result); $$ = $1 <= $3; }
  | G NET G   { printf("hit "); int result = $1 != $3 ; printf("%d \n", result); $$ = $1 != $3; }
  | G EQ G    { printf("hit ");  int result = $1 == $3 ; printf("%d \n", result); $$ = $1 == $3; } 
  | E         { $$ = $1; }
  ;

S : FLOAT VARNAME '=' E         { struct Float v; v.Name = $2 ; v.Type = $1 ; v.value=$4; addFloatVariable(v); }
  | VARNAME '=' E               { updateFloatVariable($1,$3); }                                                          
  ;

E : E '+' F     {$$ = $1 + $3;}
  | E '-' F     {$$ = $1 - $3;}
  | F           {$$ = $1;}
  ;

F : F '*' D     {$$ = $1 * $3;} 
  | F '/' D     {$$ = $1/$3;}
  | D           {$$ = $1;}
  ;

D : '(' CONDITION ')'   {$$ = ($2);}    
  | '-' D       {$$ = -$2;}
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
