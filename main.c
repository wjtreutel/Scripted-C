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
	printf(ANSI_RESET "\b\b \n");

	return 0;
	}

