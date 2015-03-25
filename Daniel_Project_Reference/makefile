ALL:Main
Main: issue.o stack.o queue.o tree.o main.o
	gcc issue.o stack.o queue.o tree.o main.o -o Main
main.o: main.c
	gcc -c main.c
stack.o: stack.c
	gcc -c stack.c
queue.o: queue.c
	gcc -c queue.c
tree.o: tree.c
	gcc -c tree.c
issue.o:issue.c
	gcc -c issue.c
clean: Main
	rm Main
