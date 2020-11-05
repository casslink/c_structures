all: BST

BST: BST.c
	gcc BST.c -o BST
clean:
	rm BST
run:
	gcc -o BST BST.c
	./BST
val:
	valgrind --leak-check=yes ./BST
