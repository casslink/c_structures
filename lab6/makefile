all: lab6

lab6: lab6.c
	gcc lab6.c -o lab6
clean:
	rm lab6
run:
	gcc -o lab6 lab6.c
	./lab6
val:
	valgrind --leak-check=yes ./lab6