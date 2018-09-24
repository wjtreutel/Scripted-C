make: 
	gcc main.c scanner.c -Wall -Wextra -o untitled -g  -ggdb

test:
	./untitled

gdb: 
	make; gdb ./untitled
