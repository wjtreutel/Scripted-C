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
#include <string.h>

#include "scanner.h"
#include "support.h"
#include "myTerminal.h"



// THE PROGRAM ITSELF

int main (int argc,char **argv) {
	printf(ANSI_RESET ANSI_GREEN);

	// Faster Testing
	if (argc > 1) {
		FILE *script = fopen(argv[1],"r");
		readScript(script);
		printf(ANSI_RESET "\n");
		return 0;
		}



	char *fileChoice;
	int quitFlag = 0;

	// Initialization
	cls();


	// Welcome Message
	printf("\t[PLEASE SELECT A RECORD TO VIEW]\n");
	printf("\t1) Terminal\n2) Conversation\n3) Quit\n> ");

	while (!quitFlag) {
		char *choice = readToken(stdin);

		// Handles user choice
		if (strcmp(choice,"1") == 0 || strcmp(choice,"Terminal") == 0) {
				fileChoice = "terminalSession.txt";
			}
		else if (strcmp(choice,"2") == 0 || strcmp(choice,"Conversation") == 0) {
				fileChoice = "conversation.txt";
			}
		else if (strcmp(choice,"3") == 0 || strcmp(choice,"Quit") == 0) {
				printf("Goodbye!\n");
				quitFlag = 1;
			}
		else {
				printf("Invalid choice. Exiting.");
				quitFlag = 1;
		}
	
		if (quitFlag) break;
		
		FILE *fp = fopen(fileChoice,"r");
		if (fp == NULL) {
			printf(ANSI_RED "ERROR: Could not find file '%s'. Exiting...\n",fileChoice);
			exit(-1);
			}

		cls();
		readScript(fp);
		printf("\n\nEND RECORD. Input any text to continue\n> ");
		fflush(stdout);
		readToken(stdin);
		cls();

		fclose(fp);
		

		printf("\t[PLEASE SELECT A RECORD TO VIEW]\n");
		printf("\t1) Terminal\n2) Conversation\n3) Quit\n> ");
		}
	
	// Cleanup
	printf(ANSI_RESET "\b\b \n");

	return 0;
	}

