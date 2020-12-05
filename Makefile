icg:
	yacc -v -d icg.y
	lex icg.l
	gcc y.tab.c lex.yy.c -o icg

clean-icg:
	rm icg