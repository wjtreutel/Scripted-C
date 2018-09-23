make:
	gcc main.c -Wall -Wextra -o untitled

test:
	make; ./untitled
