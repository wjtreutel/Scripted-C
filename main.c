/*
 * Untitled Typing Program
 *
 * Written by Liam Treutel on 9/23/18
 *
 * Absolutely not guaranteed to be compatible 
 * with anything besides Linux Mint
 */

// INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Sleep
#include <string.h>

#include "scanner.h"
#include "myTerminal.h"


// MACROS 
#define BLINK ANSI_BLINK
#define NOBLINK ANSI_NOBLINK
#define CURSOR "\x1b[5m_\x1b[25m"

#define FTYPE 167000 // "Fast TYPE" - usleep delay for normal typing
#define PROMPT "user@computer:~$ "


// FORWARD DECLARATIONS
void userMessage (char*);
void systemMessage (char*);
void newLine (void) { printf(NOBLINK "\b \n" PROMPT CURSOR); }
void readScript(FILE *);

void screenInfo(void);


// THE PROGRAM ITSELF

int main (int argc, char **argv) {
	// Initialization
	printf(ANSI_RESET ANSI_GREEN);
	//cls();

	if (argc == 1) { 
		printf("Please specify a file name. Exiting... \n"); return 0; 
		}


	FILE *fp = fopen(argv[1],"r");
	if (fp == NULL) {
		printf(ANSI_RED "ERROR: Could not find file '%s'. Exiting...\n",argv[1]);
		exit(-1);
		}
	readScript(fp);

	
	// Cleanup
	fclose(fp);
	printf(ANSI_RESET);

	return 0;
	}




void userMessage (char *text) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == '\b') {
			printf("\b \b\b" CURSOR);
			}
		else {
			printf("\b%c",text[i]);
			printf(CURSOR);
			}

		fflush(stdout);

		usleep(FTYPE);
		}
	return;
	}	


void systemMessage (char *text) {
	printf(ANSI_BOLD "\b \n%s\x1b[22m",text);
	printf("\n" PROMPT CURSOR);
	return;
	}


void readScript(FILE *script) {
	char *curr = "NULL";
	char *currMessage = "NULL";

	curr = readToken(script);

	while (!feof(script)) {


		while (!stringPending(script)) {
			printf("CURR: %s",curr);

			if (strcmp(curr,"SYS") == 0 || strcmp(curr,"S") == 0) {
				printf(ANSI_BOLD "BOLD");
				}
			else if (strcmp(curr,"USR") == 0) {
				printf(PROMPT CURSOR);
				}
			else if (strcmp(curr,"RED") == 0) {
				printf(ANSI_RED "RED");
				}
			else if (strcmp(curr,"BR") == 0) {
				printf("\nBREAK\n");
				}
			else {
				printf(ANSI_RED "ERROR: Unrecognized command '%s'\n" ANSI_RESET,curr);
				exit(-1);
				}
			}

		printf(" /  ");

		currMessage = readString(script);
		printf("MESSAGE: %s",currMessage);
		printf(ANSI_RESET ANSI_GREEN);
		printf("\n");

		curr = readToken(script);
		}
	return;
	}
