#include <stdio.h>
#include "tetris.h"


void markshape(struct block block)
/* match and mark shape of the block */
{
	switch(block.shape){
		case 0 :	// 'I' shape
			tetrix[block.hight+0][block.width]++;
			tetrix[block.hight+1][block.width]++;
			tetrix[block.hight+2][block.width]++;
			tetrix[block.hight+3][block.width]++;
		case 1 :
			
}

void movement(struct block blk, int dir)
/* 0 == left, 1 == down, 2 == right,
 * move the block to teh direction */
{
   switch(dir){
       
    case 0 : 
        if(blk.width>1) blk.width--; break;
    case 1 :
        if(blk.hight>1) blk.hight--; break;
    case 2 : 
        if(blk.width<10) blk.width++; break;
   }
}

void rotation
