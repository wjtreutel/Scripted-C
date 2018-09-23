/*
 * Untitled Typing Program
 *
 * Written by Liam Treutel on 9/23/18
 *
 * Absolutely not guaranteed to be compatible 
 * with anything besides Linux Mint
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Sleep
#include <string.h>


#include "myTerminal.h"

#define BLINK ANSI_BLINK
#define NOBLINK ANSI_NOBLINK
#define CURSOR "\x1b[5m_\x1b[25m"

#define FTYPE 167000 // "Fast TYPE" - usleep delay for normal typing

void userMessage (char*);
void systemMessage (char*);
void newline (void) { printf(NOBLINK "\b \n>" CURSOR); }

void screenInfo(void);


int main (int argc, char **argv) {
	// Initialization
	printf(ANSI_RESET);
	//cls();

	printf(ANSI_GREEN);
       	systemMessage("[WELCOME MESSAGE]\n");
	printf("Hello %s!\n",getenv("LOGNAME"));
	printf(">" CURSOR);
	fflush(stdout);
	//sleep(2);

	
//	newline();
	userMessage("Hello world");
	sleep(5);
	newline();

	userMessage("exit");
	printf("\b \n");
	printf("\n\n");

	printf(ANSI_RESET);

	return 0;
	}




void userMessage (char *text) {
	for (int i = 0; i < strlen(text); i++) {
		printf("\b%c",text[i]);
		printf(CURSOR);
		fflush(stdout);

		usleep(FTYPE);
		}
	return;
	}	


void systemMessage (char *text) {
	printf(ANSI_BOLD "%s\x1b[22m",text);

	return;
	}
