/* 
 * SUPPORT FILES FOR "UNTITLED" PROJECT
 * Written 9/23/18
 *
 */

#include <stdio.h>
#include "support.h"


void userMessage (char *text) {
	for (unsigned int i = 0; i < strlen(text); i++) {
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
	printf("%s\x1b[22m\n",text);
	return;
	}


void readScript(FILE *script) {
	char *curr = "NULL";
	char *currMessage = "NULL";
	messagePrinter printer = NULL;
	int cursorFlag = 0; // Flags for whether the cursor needs to be cleared


	curr = readToken(script);
	if (!curr) { printf(ANSI_RED "ERROR READING FILE. Exiting . . .\n" ANSI_RESET); exit(-1); }


	while (!feof(script)) {
		while (strcmp(curr,":") != 0 && strcmp(curr,"[") != 0) {
			if (strcmp(curr,"SYS") == 0 || strcmp(curr,"S") == 0) {
				printer = systemMessage;
				}
			else if (strcmp(curr,"USR") == 0) {
				printer = userMessage;
				}
			else if (strcmp(curr,"PROMPT") == 0) {
				printf(PROMPT CURSOR);
				}
			else if (strcmp(curr,"BR") == 0) {
				printf("\n");
				}

			else if (strcmp(curr,"BK") == 0) { 
				userMessage("\b");
				}

			else if (strcmp(curr,"RED") == 0) {
				printf(ANSI_RED);
				}
			else if (strcmp(curr,"BOLD") == 0) {
				printf(ANSI_BOLD);
				}
			else if (strcmp(curr,"SLEEP") == 0 || strcmp(curr,"WAIT") == 0) {
				int sleepTime = readInt(script);
				sleep(sleepTime);
				}
			else {
				printf(ANSI_RED "ERROR: Unrecognized command '%s'\n" ANSI_RESET,curr);
				exit(-1);
				}

			fflush(stdout);

			if (stringPending(script)) curr = ":"; // Allows option of omitting ':' 
			else curr = readToken(script);
			}




		// Preparation for message
		if (cursorFlag) printf("\b \n"); 
		if (printer == NULL) { 
			printf(ANSI_RED "ERROR: No message origin specified. Exiting . . .\n" ANSI_RESET);
			exit(-1);
			}

		
		// Multi Part Message
		if (strcmp(curr,"[") == 0) {
			while (strcmp(curr,"]") != 0) {
				if (stringPending(script)) {
					currMessage = readString(script);
					printer(currMessage);
					}
				else { 
					printf("CURR: %s",curr);
					}
				curr = readToken(script);
				}
			}


		// Single Part Message
		else {	
			currMessage = readString(script);
			printer(currMessage);
			}


		// Cleanup
		printf(ANSI_RESET ANSI_GREEN);
		if (printer == userMessage) cursorFlag = 1;
		else cursorFlag = 0;
		printer = NULL;

		curr = readToken(script);
		}
	return;
	}


