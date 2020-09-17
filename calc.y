%{
#include<stdio.h>
#include<stdlib.h>
extern int yylex();    
void yyerror(char *msg);
%}

%union{
   float f;
   int i;
}

%start M
%token<f> FNUM
%type<f> E F G T

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
  | G           {$$ = $1;}
  ;

G : G '/' T     {$$ = $1/$3;}
  | T           {$$ = $1;}    
  ; 

T : '(' E ')'   {$$ = ($2);}    
  | '-' T       {$$ = -$2;}
  | FNUM        {$$ = $1;}
  ;  
%%

void yyerror(char *msg){
    fprintf(stderr,"%s\n",msg);
    exit(1);
}

int main(){
    yyparse();
    return 0;
}
