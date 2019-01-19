/* visualize the function of game */

#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "tetris.h"


void print_frame()
/* print the main frame of game */
{
    initscr();
    curs_set(0);

    clear();
    move(0,0);
    addstr(" ==================== \n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr("|                    |\n");
    addstr(" ==================== ");
    refresh();


    curs_set(1);
    endwin();
}

void printblock()
/* print the shape of blocks based on the data in tetrix */
{
	
}

