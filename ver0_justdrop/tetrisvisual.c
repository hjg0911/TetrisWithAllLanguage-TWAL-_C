/* visualize the function of game */

#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "tetris.h"


void print_frame()
/* print the main frame of game */
{
    move(0,0);
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
    addstr(" *WellcomeToMyTetris* ");
    refresh();
}

void print_tetrix()
/* print the shape of blocks based on the data in tetrix */
{
	for(int i = 20; i>0 ; i--){
		for(int j = 1; j<11; j++){
			move(20-i,2*(j-1)+1);
			if(tetrix[i][j] > 0){
				standout();
				addstr("  ");
				standend();
			}
			else{
				addstr("  ");
			}
		}
	}
	refresh();
}

