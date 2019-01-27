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
	for(int i = MAX_HIGHT-5; i>0 ; i--){
		for(int j = 1; j< MAX_WIDTH-1; j++){
			move((MAX_HIGHT-5)-i,2*(j-1)+1);
			if(tetrix[i][j] > 0){
				standout();
				printw("  ");
				standend();
			}
			else{
				printw("  ");
			}
		}
	}
	refresh();
}

