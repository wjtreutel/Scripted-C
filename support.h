#ifndef SUPPORT_H
#define SUPPORT_H

// MACROS 

#define FTYPE 167000 // "Fast TYPE" - usleep delay for normal typing
#define PROMPT "user@computer:~$ "
#define CURSOR "\x1b[5m_\x1b[25m"

typedef void (*messagePrinter)(char*);


// FORWARD DECLARATIONS  (Move all to support file)
void userMessage (char*);
void systemMessage (char*);
//'void newLine (void) { printf(NOBLINK "\b \n" PROMPT CURSOR); }
void readScript(FILE *);

#endif
