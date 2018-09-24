make: 
	gcc main.c support.c scanner.c -Wall -Wextra -o game -g  -ggdb

test:
	./game

gdb: 
	make; gdb ./untitled
