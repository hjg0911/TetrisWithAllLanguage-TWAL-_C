#include <stdio.h>
#include <unistd.h> //for usleep
#include <stdlib.h> // for rand(), srand()
#include <time.h> // for time()
#include <curses.h>
#include "tetris.h"

#define SPEED 15

void tetris_play();



int main()
{
	initscr();
	//init_pair(1, COLOR_WHITE, COLOR_RED);
	curs_set(0);

	tetris_play();

	curs_set(1);
	endwin();
    
	return 0;
}

void tetris_play()
{

	struct block newBlock;

	init_tetrix();
	srand(time(NULL));

	print_frame();

	while(!isgameEnd()){ //while game play
		back_up_tetrix(0,tetrix);
		newBlock = make_block(rand() % 6);
		
		while(!isTouch(movement(newBlock,1))){ //while one block drop
			newBlock = movement(newBlock,1);
			back_up_tetrix(1,tetrix);
			mark_shape(tetrix,newBlock);
			print_tetrix();
		//	sleep(1);

move(34,0);
for(int i=0; i <MAX_HIGHT; i++){
for(int j=0; j <MAX_WIDTH; j++)
{printw("%d ",tetrix[i][j]);}
printw("\n");}
refresh();
usleep(1000000/SPEED);
		}
		
	}

	clear();
	standout();
	mvprintw(9,6,"GAME OVER");
	standend();	
	refresh();
	getchar();
}



