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
int elseAllowed = 1;
void actionHandler(int stackTop, int conditionResult, char *condition); 
int firstElseIf = 0;
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

PRINTER  : DISPLAY E  { if(top()==1 ) {  printf(" \n \n  <-------- DISPLAYING : %f ---------------> \n \n",$2); } }
         ;

/*
Previous if else logic 
*/
CONTROL : IF '(' CONDITIONALEXPRESSION ')' EXP    {  pop();  };
        | IF '(' CONDITIONALEXPRESSION ')' EXP EXTRA EEXP { pop(); }
        | IF '(' CONDITIONALEXPRESSION ')' EXP  EEXP   { pop(); }
        ;

EXTRA : EXTRA ELSEIF '(' CONDITIONALEXPRESSION ')' EXP    { if(top()==0) {  }else{ } }  
      | ELSEIF '(' CONDITIONALEXPRESSION ')' EXP        {  if(top()==0){  }else{ }  }
      ;


EEXP : ELSE {  if( elseAllowed == 1 && top() == 0 ){ push(1); } else { push(0); }} '{' M '}' { pop(); }
     ; 

EXP : '{' M '}'       {  pop();  }   
    ;

CONDITIONALEXPRESSION : CONDITION     { 
                                        printStack(); 
                                        int topval = top(); 
                                        int result = (int)($1);  
                                        char * condition = $<s>-1;
                                        actionHandler(topval, result , condition); 
                                      }
                      ;

CONDITION : CONDITION OR CONDITION  {  int result = $1 || $3 ;  $$ = $1 || $3; }
          | CONDITION AND CONDITION {  int result = $1 && $3 ;  $$ = $1 && $3; }
          | NOT CONDITION           {  int result = $2 == 0 ? 1 : 0 ; $$ = ($2 == 0 ? 1 : 0) ; } 
          | G
          ;                                         

G : G '<' G   {  int result = $1 < $3 ;  $$ = (int)($1 < $3); }
  | G '>' G   {  int result = $1 > $3 ;  $$ = $1 > $3; }
  | G GTE G   {  int result = $1 >= $3 ;  $$ = $1 >= $3; }
  | G LTE G   {  int result = $1 <= $3 ;  $$ = $1 <= $3; }
  | G NET G   {  int result = $1 != $3 ;  $$ = $1 != $3; }
  | G EQ G    {  int result = $1 == $3 ;  $$ = $1 == $3; } 
  | E         {  $$ = $1; }
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


void actionHandler(int stackTop, int conditionResult, char *condition)
{
    int absoluteTop = stack[0];
    
    if (absoluteTop == -1)
    {
        push(conditionResult);
        push(conditionResult);
        printf(" ***** first if conditions absolute value :: %d and result %d***** \n",  absoluteTop, conditionResult);
    }
    else
    {
        if (stackTop == 0)
        {
            if (isIF(condition) == 1)
            {
                push(0);
                push(0);
                elseAllowed = 0;
            }
            else if (top() == 0 && isELSEIF(condition) == 1 && parentAllowed() == 1)
            {   
                pop();
                push(conditionResult);
                push(conditionResult);
                elseAllowed = conditionResult == 1 ? 0 : 1;
                printf("----------------- IS ELSE ALLOWED %d \n -----------------", elseAllowed);
            }
            else
            {
                push(0);
                // 
                elseAllowed == 1;
            }
        }
        else
        {
            if (isIF(condition) == 1)
            {
                push(conditionResult);
                push(conditionResult);
                elseAllowed = !conditionResult;
            }
            else
            {
                printf("--     hit else \n    --");
                push(0);
                elseAllowed = 1;
            }
        }
    }
}