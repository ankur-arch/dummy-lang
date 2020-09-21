%{
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Types.h"
extern int yylex();
int stackPosition = 0 ;
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
%token<s> FLOAT IF ELSE
%token<s> VARNAME
%token<f> FNUM
%token '<' '>' LTE GTE EQ NOT NET AND OR  DISPLAY RETURN 
%type<s> M S PRINTER 
%type<f> G CONDITIONALEXPRESSION CONDITION
%type<s>  THENSTMT OTHERSTMT
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

CONTROL : IF '(' CONDITIONALEXPRESSION ')' THENSTMT    { int status = top(); if( status==1 || status==-1 ){ printf("address in if =>control :%p condition : %p Statement : %p \n",&$$, &$3, &$<s>5);}else printf("Skipped If condition \n");}
        | IF '(' CONDITIONALEXPRESSION ')' THENSTMT ELSE OTHERSTMT { printf("if - else condition %s \n", $<s>6); }
        ;

CONDITIONALEXPRESSION : CONDITION     { printf("pushed into conditional \n"); push(!(int)($1)); push((int)($1));}
                      ;

THENSTMT : '{' RETURN E ';''}'   { int resultif = (int)($<f>-1) ;  printf("inside if the single statement address : %p \n", &$<s>$); printf("the address inside the statement %p  with the value being %d\n", &$<f>-1, resultif ); if(resultif == 1){ printf("The returned value %f \n",$3); } pop(); }
         | '{' M '}'             {  int resultif = (int)($<f>-1) ; printf("the address inside the statement block %p  with the value being %d\n", &$<f>-1, resultif ); if(resultif == 1){ printf("BLOCK CONDITION MISMATCH \n") ; } pop();  }
         ;

OTHERSTMT : '{' RETURN E ';' '}' ';'  { int resultif = (int)($<f>-3) ; top();  printf("the address inside the ELSE statement %p  with the value being %d\n",  &$<f>-3, resultif ); if(resultif != 1){ printf("The returned else value %f \n",$3); }  }
          ;


CONDITION : CONDITION OR CONDITION  {  int result = $1 || $3 ; printf("expression %d \n", result); $$ = $1 || $3; }
          | CONDITION AND CONDITION {  int result = $1 && $3 ; printf("expression %d \n", result); $$ = $1 && $3; }
          | NOT CONDITION           {  int result = $2 == 0 ? 1 : 0 ; printf("expression %d \n", result); $$ = ($2 == 0 ? 1 : 0) ; } 
          | G
          ;                                         

G : G '<' G   { printf("hit lt \n"); int result = $1 < $3 ; printf("%d \n", result); $$ = (int)($1 < $3); }
  | G '>' G   { printf("hit gt \n");  int result = $1 > $3 ; printf("%d \n", result); $$ = $1 > $3; }
  | G GTE G   { printf("hit >= \n");  int result = $1 >= $3 ; printf("%d \n", result); $$ = $1 >= $3; }
  | G LTE G   {  printf("hit <= \n");  int result = $1 <= $3 ; printf("%d \n", result); $$ = $1 <= $3; }
  | G NET G   { printf("hit != \n"); int result = $1 != $3 ; printf("%d \n", result); $$ = $1 != $3; }
  | G EQ G    { printf("hit == \n");  int result = $1 == $3 ; printf("%d \n", result); $$ = $1 == $3; } 
  | E         { printf(" Reached E with stack top %d \n", top()) ; $$ = $1; }
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
