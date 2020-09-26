%{
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "Types.h"
extern int yylex();
int stackPosition = -1 ;
int FloatVariableStackCounter = 0;
int yydebug = 1;    
void yyerror(char *msg);
int elseAllowed = 1;
void actionHandler(int stackTop, int conditionResult, char *condition); 
int firstElseIf = 0;
int functionReturnTypeNumber = -1 ; 
int functionReturnTypeVoid = -1 ; 
int integerVariableEncountered = 0 , floatVariableEncountered = 0 ; 
int printInt = 0 ;
int enteredAssignment = 1; 
int functionReturnsInt = 0 ;
%}

%union{
   float f;
   int i;
   char* s;
   Number n;
}


%start Start
%token<s> VOID INT FLOAT IF ELSE ELSEIF INCR DECR 
%token<s> VARNAME
%token<f> FNUM
%token '<' '>' LTE GTE EQ NOT NET AND OR  DISPLAY RETURN 
%token  PLUSASSIGN MINUSASSIGN MULASSIGN DIVASSIGN MODASSIGN 
%type<s> BLOCK LINE PRINTER 
%type<s> ASSIGNMENT 
%type<n> ASSIGN FINALVAR
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
Start : BLOCK
      | FLOAT  VARNAME '(' { functionReturnTypeNumber = 1 ; } ')' '{' BLOCK '}' { if(functionReturnTypeNumber != 0 ){ printf("\n Error Function does not return any value \n")  ; exit(0); };  functionReturnTypeNumber = -1 ; }
      | INT  VARNAME '(' { functionReturnTypeNumber = 1 ; functionReturnsInt = 1 ; } ')' '{' BLOCK '}' { if(functionReturnTypeNumber != 0 ){ printf("\n Error Function does not return any value \n")  ; exit(0); };  functionReturnTypeNumber = -1 ; }
      | VOID  VARNAME '(' { functionReturnTypeVoid = 1 ;  } ')' '{' BLOCK '}' { functionReturnTypeVoid = -1 ; }
      ;

BLOCK : LINE        {;}
  | BLOCK LINE      {;}
  | CONTROL  {;}
  | BLOCK CONTROL  {;}
  | CONDITION ';'       {;}        
  | BLOCK CONDITION ';'     {;}
  ; 

LINE : ASSIGNMENT         
  | VARNAME '=' E ';'       { if(top()==1 || top()==-1 ) { updateFloatVariable($1,$3); } }
  | VARNAME PLUSASSIGN E ';' { if(top()==1 || top()==-1 ) {  Number v = getFloatVariableValue($1); updateFloatVariable($1 , v.value+$3); } }
  | VARNAME MINUSASSIGN E ';' { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($1); updateFloatVariable($1 , v.value-$3); }}
  | VARNAME MULASSIGN E ';' { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($1); updateFloatVariable($1 , v.value*$3); }}
  | VARNAME DIVASSIGN E ';' { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($1); updateFloatVariable($1 , v.value/$3); }}
  | VARNAME MODASSIGN E ';' { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($1); updateFloatVariable($1 , (int)(v.value)%(int)($3)); }}
  | PRINTER ';'            {;}                                                          
  ;

ASSIGNMENT : FLOAT  ASSIGN ';' { if(top()==1 || top()==-1 ) { integerVariableEncountered = 0; }  }
            |INT ASSIGN ';'  { if(top()==1 || top()==-1 ) { integerVariableEncountered = 1 ; } }
            ; 

ASSIGN : ASSIGN ',' FINALVAR  { if(top()==1 || top()==-1 ) { $$=$3; addFloatVariable($3);} }
   | FINALVAR                 { if(top()==1 || top()==-1 ) { $$=$1; addFloatVariable($1); }  }
   ;

FINALVAR :  VARNAME '=' E { if(top()==1 || top()==-1 ) { Number v ; v.isInteger = integerVariableEncountered ; v.Name = $1; v.value = $3  ;  v.isIntitialized = 1 ; $$ = v; }} 
         |  VARNAME  { if(top()==1 || top()==-1 ) { Number v ; v.Name = $1; v.isIntitialized = 0; v.isInteger = integerVariableEncountered   ; v.value=-1; $$ = v; }}
         ; 

PRINTER  : DISPLAY E   {   if(top()==1 || top()==-1 ) { printf(" \n printed  : %f \n",($2));} }
         | RETURN E    {   if(functionReturnTypeVoid == 1){  printf("\n Function type void cannot return any value \n")  ; exit(0); };  if(top()==1 || top()==-1 ) { functionReturnTypeNumber = 0 ; functionReturnsInt == 1 ? printf(" \n returned : %d \n",(int)($2)) : printf(" \n returned : %f \n",$2); functionReturnsInt = 0; exit(0);  } }
         | RETURN      {  if(top()==1 || top()==-1) { if(functionReturnTypeNumber == 1){ printf("\n Error Function type does not return a value \n")  ; exit(0); }; printf(" \n returned \n "); exit(0); } }
         ;

CONTROL : IF '(' CONDITIONALEXPRESSION ')' EXP    {  pop();  };
        | IF '(' CONDITIONALEXPRESSION ')' EXP EXTRA EEXP { pop(); }
        | IF '(' CONDITIONALEXPRESSION ')' EXP  EEXP   { pop(); }
        ;

EXTRA : EXTRA ELSEIF '(' CONDITIONALEXPRESSION ')' EXP    { ; }  
      | ELSEIF '(' CONDITIONALEXPRESSION ')' EXP        {  ; }
      ;


EEXP : ELSE {  if(top()==0 && parentAllowed()==1 ){  push(1); } else { push(0); }} '{' BLOCK '}' { pop(); }
     ; 

EXP : '{' BLOCK '}'       {  pop();  }   
    ;

CONDITIONALEXPRESSION : CONDITION     { 
                                         
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


E : E '+' F     { $$ = $1 + $3; }
  | E '-' F     { $$ = $1 - $3; }
  | F           { $$ = $1; }
  ;

F : F '*' D     { $$ = $1 * $3; } 
  | F '/' D     { $$ = $1/$3; }
  | D           { $$ = $1; }
  ;

D : '(' CONDITION ')'   { $$ = ($2); }    
  | '-' D       { $$ = -1*$2; }
  | L           { $$ = $1; } 
  ;

L : FNUM        { if(top()==1 || top()==-1 ) {$$ = $1;} }
  | VARNAME     { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($1); printInt = !v.isInteger; $$ = v.value; }}
  | VARNAME INCR     {if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($1); updateFloatVariable(v.Name,v.value+1); printInt = !v.isInteger; $$ = v.value; }}
  | VARNAME DECR    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($1); updateFloatVariable(v.Name,v.value-1); printInt = !v.isInteger; $$ = v.value; }}
  | INCR VARNAME     { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($2); updateFloatVariable(v.Name,v.value+1); printInt = !v.isInteger; $$ = v.value+1; }}
  | DECR VARNAME     { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue($2); updateFloatVariable(v.Name,v.value-1); printInt = !v.isInteger; $$ = v.value-1; }}
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
                elseAllowed = (int)(conditionResult == 1 ? 0 : 1);
                
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
                push(0);
                elseAllowed = 1;
            }
        }
    }
}