all : calc

calc: lex.yy.c TypeUtils.c y.tab.c
	gcc -g lex.yy.c TypeUtils.c y.tab.c -o calc

lex.yy.c: y.tab.c calc.l
	lex calc.l

y.tab.c: calc.y
	yacc -d calc.y

TypeUtils.c: 
	gcc TypeUtils.c -o TypeUtils 

clean: 
	rm -rf lex.yy.c y.tab.c y.tab.h calc calc.dSYM