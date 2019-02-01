all:
	gcc -E .\getint.c -o getint.i
	gcc -S .\getint.i -o getint.s
	gcc -c .\getint.s -o getint.o
	gcc getint.o -o getint
	gcc getint.c -o getint
	gcc -O2 -o test getint.c