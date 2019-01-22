#include <stdio.h>
#include "tetris.h"



void init_tetrix()
/* initialize the tetrix */
{
	for(int i = 0; i<25; i++)
		for(int j = 0; j<12; j++){
			if(i==0) tetrix[i][j] = 1;
			else tetrix[i][j] = 0;
		}
}

struct block make_block(int shp)
/* make the new block has shape of shp */
{
	struct block blk;


	blk.hight = 21;
	blk.width = 5; 
	blk.shape = shp;
	
	return blk;
}


void mark_shape(struct block block)
/* match and mark shape of the block */
{
	switch(block.shape){
		case 0 :	// 'I' shape
			tetrix[block.hight+0][block.width]++;
			tetrix[block.hight+1][block.width]++;
			tetrix[block.hight+2][block.width]++;
			tetrix[block.hight+3][block.width]++;
			break;

		case 1 :	// 'O' mino
			tetrix[block.hight+0][block.width+0]++;
			tetrix[block.hight+0][block.width+1]++;
			tetrix[block.hight+1][block.width]++;
			tetrix[block.hight+1][block.width+1]++;
			break;
		case 2 :    // 'Z' mino
			tetrix[block.hight][block.width]++;
			tetrix[block.hight][block.width-1]++;
			tetrix[block.hight+1][block.width-1]++;
			tetrix[block.hight+1][block.width-2]++;
			break;
		case 3 :	// 'S' mino
			tetrix[block.hight][block.width]++;
			tetrix[block.hight][block.width+1]++;
			tetrix[block.hight+1][block.width+1]++;
			tetrix[block.hight+1][block.width+2]++;
			break;
		case 4 :	// 'J' mino
			tetrix[block.hight][block.width]++;
			tetrix[block.hight][block.width-1]++;
			tetrix[block.hight+1][block.width]++;
			tetrix[block.hight+2][block.width]++;
			break;
		case 5 :	// 'L' mino
			tetrix[block.hight][block.width]++;
			tetrix[block.hight][block.width+1]++;
			tetrix[block.hight+1][block.width]++;
			tetrix[block.hight+2][block.width]++;
			break;
		case 6 :	// 'T' mino
			tetrix[block.hight][block.width]++;
			tetrix[block.hight][block.width-1]++;
			tetrix[block.hight][block.width+1]++;
			tetrix[block.hight+1][block.width]++;
			break;
	}
}



void movement(struct block *blk, int dir)
/* 0 == left, 1 == down, 2 == right,
 * move the block to teh direction */
{
   switch(dir){
       
    case 0 : 
        if(blk->width>1) blk->width--; break;
    case 1 :
        if(blk->hight>1) blk->hight--; break;
    case 2 : 
        if(blk->width<10) blk->width++; break;
   }
}

int isTouch()
/* if touched block exist, return how many block touched
 * else, return 0*/
{
	int istch = 0;

	for(int i = 0; i<25; i++)
		for(int j = 0; j<12; j++)
			if(tetrix[i][j]>1) istch++;

	return istch++;
}

// void rotation()
