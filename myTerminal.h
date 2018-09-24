/*
 * ANSI.H - Useful Terminal Macros
 *
 * Written by Liam Treutel
 */

#ifndef MYTERMINAL_H
#define MYTERMINAL_H



/* USEFUL MACROS */
#define cls() printf("\x1b[H\x1b[J");  // Clears screen




/* ANSI COMMANDS */

// Resets all ANSI options
#define ANSI_RESET   "\x1b[0m" 

// Effects
#define ANSI_BOLD "\x1b[1m"
#define ANSI_FAINT "\x1b[2m"
#define ANSI_ITALIC "\x1b[3m"
#define ANSI_UNDERLINE "\x1b[4m"
#define ANSI_BLINK "\x1b[5m"
#define ANSI_REVERSE_COLORS "\x1b[7m"
#define ANSI_CONCEALED "\x1b[8m"
#define ANSI_CROSSED "\x1b[9m"

#define ANSI_NOBLINK "\x1b[25m"

// Foreground Colors
#define ANSI_BLACK   "\x1b[90m"
#define ANSI_RED     "\x1b[91m"
#define ANSI_GREEN   "\x1b[92m"
#define ANSI_YELLOW  "\x1b[93m"
#define ANSI_BLUE    "\x1b[94m"
#define ANSI_MAGENTA "\x1b[95m"
#define ANSI_CYAN    "\x1b[96m"
#define ANSI_WHITE   "\x1b[97m"

// Background Colors
#define ANSI_BLACK_BG   "\x1b[40m"
#define ANSI_RED_BG     "\x1b[41m"
#define ANSI_GREEN_BG   "\x1b[42m"
#define ANSI_YELLOW_BG  "\x1b[43m"
#define ANSI_BLUE_BG    "\x1b[44m"
#define ANSI_MAGENTA_BG "\x1b[45m"
#define ANSI_CYAN_BG    "\x1b[46m"
#define ANSI_WHITE_BG   "\x1b[47m"



#endif
