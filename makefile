make: 
	gcc main.c support.c scanner.c -Wall -Wextra -o untitled -g  -ggdb

test:
	./untitled script.txt

gdb: 
	make; gdb ./untitled
