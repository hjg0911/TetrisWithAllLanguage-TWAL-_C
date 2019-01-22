#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // for rand(), srand()
#include <time.h> // for time()
#include <curses.h>
#include "tetris.h"

void tetris_play();
void test();

int main()
{
	initscr();
	curs_set(0);

	tetris_play();

	curs_set(1);
	endwin();
    return 0;
}

void tetris_play()
{

	struct block newBlock;
	int curStatus[25][12];
	
	init_tetrix();
	srand(time(NULL));

	print_frame();

	while(1){

		for(int i = 0; i < 25; i++)   //back up the tetrix
			for(int j = 0; j < 12; j++)
				curStatus[i][j] = tetrix[i][j];
		newBlock = make_block(rand() % 6);
		
		while(!isTouch()){
			movement(&newBlock,1);			
			for(int i = 0; i < 25; i++)		// get the tetrix
				for(int j = 0; j < 12; j++)
					tetrix[i][j] = curStatus[i][j];
			mark_shape(newBlock);
			print_tetrix();
			sleep(1);
		}
	}

}
void test()
{
	struct block testblock;

	int curStatus[25][12];
	init_tetrix();
	srand(time(NULL));
	testblock = make_block(1);

	printf("%d\n\n\n\n\n\n\n",testblock.shape);

			for(int i = 0; i < 25; i++)   //back up the tetrix
			for(int j = 0; j < 12; j++)
				curStatus[i][j] = tetrix[i][j];
	
	movement(&testblock,1);
	mark_shape(testblock);
	for(int i = 20 ; i > 0 ; i--){
		for(int j = 1 ; j <11 ; j++)
			printf("%d",tetrix[i][j]);
		printf("\n");
	}

	printf("\n\n\n\n");

	movement(&testblock,1);
			for(int i = 0; i < 25; i++)   //back up the tetrix
			for(int j = 0; j < 12; j++)
				tetrix[i][j] = curStatus[i][j];
	mark_shape(testblock);	
	for(int i = 20 ; i > 0 ; i--){
		for(int j = 1 ; j <11 ; j++)
			printf("%d",tetrix[i][j]);
		printf("\n");
	}


}



