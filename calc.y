%{
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Types.h"
extern int yylex();
int stackPosition = -1 ;
int FloatVariableStackCounter = 0;
int yydebug = 1;    
void yyerror(char *msg);
%}


%union{
   float f;
   int i;
   char* s;
}

%start Start
%token<s> FLOAT IF ELSE ELSEIF
%token<s> VARNAME
%token<f> FNUM
%token '<' '>' LTE GTE EQ NOT NET AND OR  DISPLAY RETURN 
%type<s> M S PRINTER 
%type<f> G CONDITIONALEXPRESSION CONDITION
%type<s>  EXP EXTRA EEXP
%type<s>  CONTROL 
%type<f> E F L D 
%nonassoc IF
%nonassoc ELSE 
%left GTE LTE EQ NET '>' '<'
%left OR
%left AND
%left NOT 
%left '+' '-'
%left '*' 
%left '/'

%%
Start : M
      ;

M : S        {;}
  | M S      {;}
  | CONTROL  {;}
  | M CONTROL  {;}
  | CONDITION ';'       {;}        
  | M CONDITION ';'     {;}
  ; 

S : FLOAT VARNAME '=' E ';'        { struct Float v; v.Name = $2 ; v.Type = $1 ; v.value=$4; addFloatVariable(v); }
  | VARNAME '=' E ';'              { updateFloatVariable($1,$3); }
  | PRINTER ';'            {;}                                                          
  ;

PRINTER  : DISPLAY E  { printf("Inside display \n"); top() ; printf("%f \n",$2); }
         ;

/*
Previous if else logic 
*/
CONTROL : IF '(' CONDITIONALEXPRESSION ')' EXP    {  printf(" **** Simple if \n"); };
        | IF '(' CONDITIONALEXPRESSION ')' EXP EXTRA EEXP { printf(" **** IF ELSEIF ELSE  \n "); }
        | IF '(' CONDITIONALEXPRESSION ')' EXP  EEXP   { printf(" **** Simple if else \n"); };
        ;

EXTRA : EXTRA ELSEIF '(' CONDITIONALEXPRESSION ')' EXP    { printf(" *** Ended else if \n "); }  
      | ELSEIF '(' CONDITIONALEXPRESSION ')' EXP        { printf(" *** Added else if \n "); }
      ;


EEXP : ELSE '{' M '}'       { if( top() == 0 ){ pop(); push(1) ; printf(" *** Special else check \n "); } }
     ; 
EXP : '{' M '}'       { if( top() == 1 ) { printf(" *** <--> expression returned from control flow logic M \n "); } else {printf(" expression declined \n"); } }   
    ;

CONDITIONALEXPRESSION : CONDITION     { int topval = top(); if(topval==-1 || topval == 1 ){ push((int)($1)); }; if(topval==0){ pop(); push((int)($1)); }; printf(" ----> Entered conditional statement \n"); }
                      ;

CONDITION : CONDITION OR CONDITION  {  int result = $1 || $3 ; printf(" Condition --> expression %d \n", result); $$ = $1 || $3; }
          | CONDITION AND CONDITION {  int result = $1 && $3 ; printf(" Condition --> expression %d \n", result); $$ = $1 && $3; }
          | NOT CONDITION           {  int result = $2 == 0 ? 1 : 0 ; printf(" Condition --> expression %d \n", result); $$ = ($2 == 0 ? 1 : 0) ; } 
          | G
          ;                                         

G : G '<' G   { printf(" -> hit lt \n"); int result = $1 < $3 ; printf("%d \n", result); $$ = (int)($1 < $3); }
  | G '>' G   { printf(" -> hit gt \n");  int result = $1 > $3 ; printf("%d \n", result); $$ = $1 > $3; }
  | G GTE G   { printf(" -> hit >= \n");  int result = $1 >= $3 ; printf("%d \n", result); $$ = $1 >= $3; }
  | G LTE G   {  printf(" -> hit <= \n");  int result = $1 <= $3 ; printf("%d \n", result); $$ = $1 <= $3; }
  | G NET G   { printf(" -> hit != \n"); int result = $1 != $3 ; printf("%d \n", result); $$ = $1 != $3; }
  | G EQ G    { printf(" -> hit == \n");  int result = $1 == $3 ; printf("%d \n", result); $$ = $1 == $3; } 
  | E         { printf(" ---> Reached E with stack top value :  %d \n", top()) ; $$ = $1; }
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
  | '-' D       {$$ = -1*$2;}
  | L           {$$ = $1;} 
  ;

L : FNUM        {$$ = $1;}
  | VARNAME     {$$ = getFloatVariableValue($1); }
  ;    
%%

void yyerror(char *msg){
    fprintf(stderr,"%s on the line\n",msg);
    exit(1);
}

int main(){
    for(int x=0 ; x< MAX_SLOT ; x++){
      FloatVariableTable[x].Name = "";
      FloatVariableTable[x].Type = "Float";
      FloatVariableTable[x].value = 0.0;
      stack[x] = -1;
    };

    yyparse();
    return 0;
}
