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
}

%start M
%token<f> FNUM
%token LT GT LTE GTE ET EQ NOT NET AND OR 
%type<f> E F G 

%%
M : S ';'       {;}              
  | M S ';'     {;}

S : E           {printf(" %f \n",$1) ;}
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
  | FNUM        {$$ = $1;}
  ;  
%%

void yyerror(char *msg){
    fprintf(stderr,"%s\n",msg);
    exit(1);
}

int main(){
    struct Float v, v2, v3, v4;
    v.Name = "hasan";
    v.Type = "Float";
    v.value = 100;

    v2.Name = "hasan";
    v2.Type = "Float";
    v2.value = 30;

    v3.Name = "Mahasan";
    v3.Type = "Float";
    v3.value = 120;

    addFloatVariable(v);

    addFloatVariable(v3);
    float man = getFloatVariableValue("Mahasan");
    printf("The value of the search function is %f \n", man);
    printf("Hello world %s , value : %f \n %d \n", FloatVariableTable[0].Name, FloatVariableTable[0].value, FloatVariableStackCounter);
    updateFloatVariable("hasan",525);
    printf("Hello world %s , value : %f \n %d \n", FloatVariableTable[0].Name, FloatVariableTable[0].value ,FloatVariableStackCounter);
    yyparse();
    return 0;
}
