#include <stdio.h>
#include "tetris.h"



void init_tetrix()
/* initialize the tetrix */
{
	for(int i = 0; i<MAX_HIGHT; i++)
		for(int j = 0; j<MAX_WIDTH; j++){
			if(i==0) tetrix[i][j] = 1;
			else tetrix[i][j] = 0;
		}
}

struct block make_block(int shp)
/* make the new block has shape of shp */
{
	struct block blk;


	blk.hight = MAX_HIGHT-4;
	blk.width = MAX_WIDTH/2; 
	blk.shape = shp;
	
	return blk;
}


void mark_shape(int matrix[][MAX_WIDTH], struct block block)
/* match and mark shape of the block */
{
	switch(block.shape){
		case 0 :	// 'I' shape
			matrix[block.hight+0][block.width]++;
			matrix[block.hight+1][block.width]++;
			matrix[block.hight+2][block.width]++;
			matrix[block.hight+3][block.width]++;
			break;

		case 1 :	// 'O' mino
			matrix[block.hight+0][block.width+0]++;
			matrix[block.hight+0][block.width+1]++;
			matrix[block.hight+1][block.width]++;
			matrix[block.hight+1][block.width+1]++;
			break;
		case 2 :    // 'Z' mino
			matrix[block.hight][block.width]++;
			matrix[block.hight][block.width-1]++;
			matrix[block.hight+1][block.width-1]++;
			matrix[block.hight+1][block.width-2]++;
			break;
		case 3 :	// 'S' mino
			matrix[block.hight][block.width]++;
			matrix[block.hight][block.width+1]++;
			matrix[block.hight+1][block.width+1]++;
			matrix[block.hight+1][block.width+2]++;
			break;
		case 4 :	// 'J' mino
			matrix[block.hight][block.width]++;
			matrix[block.hight][block.width-1]++;
			matrix[block.hight+1][block.width]++;
			matrix[block.hight+2][block.width]++;
			break;
		case 5 :	// 'L' mino
			matrix[block.hight][block.width]++;
			matrix[block.hight][block.width+1]++;
			matrix[block.hight+1][block.width]++;
			matrix[block.hight+2][block.width]++;
			break;
		case 6 :	// 'T' mino
			matrix[block.hight][block.width]++;
			matrix[block.hight][block.width-1]++;
			matrix[block.hight][block.width+1]++;
			matrix[block.hight+1][block.width]++;
			break;
	}
}



struct block movement(struct block blk, int dir)
/* 0 == left, 1 == down, 2 == right,
 * move the block to teh direction 
 * return 0 : success movement
 * return 1 : fail movement (bottom arrived)
 * return 2 : fail movement (side wall blocked) */
{

    switch(dir){
       
    case 0 : blk.width--; break;
    case 1 : blk.hight--; break;
	case 2 : blk.width++; break;
   }
   
   return blk;
}

int isTouch(struct block nextBlock)
/* if touched block exist, return how many block touched
 * else, return 0*/
{
	int istch = 0;	
	int vtetrix[MAX_HIGHT][MAX_WIDTH];

	back_up_tetrix(1,vtetrix);
	mark_shape(vtetrix, nextBlock);
	for(int i=0; i<MAX_HIGHT; i++){
		for(int j=0; j<MAX_WIDTH; j++){
			if(vtetrix[i][j] > 1) istch++;
		}
	}

	return istch;
}

void back_up_tetrix(int n, int matrix[][MAX_WIDTH])
/* 0 : save current matrix status to a back_up matrix
 * 1 : load the matrix saved */
{
	static int temp[MAX_HIGHT][MAX_WIDTH];

	switch(n){
		
		case 0 : // save the back_up of current tetrix
			for(int i = 0; i < MAX_HIGHT; i++){   
				for(int j = 0; j < MAX_WIDTH; j++){
					temp[i][j] = matrix[i][j];
				}
			}
			break;
		
		case 1 : // load the saved
			for(int i = 0; i < MAX_HIGHT; i++){	
				for(int j = 0; j < MAX_WIDTH; j++){
					matrix[i][j] = temp[i][j];
				}
			}
			break;
	}
	
	
}

int isgameEnd()
{
	for(int i=1; i<MAX_WIDTH-1; i++){
		if(tetrix[MAX_HIGHT-5][i] > 0) return 1;
	}
	return 0;
	
}

// void rotation()
