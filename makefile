main.out: function.o
	gcc function.o main.c
function.o: function.c
	gcc -c function.c
