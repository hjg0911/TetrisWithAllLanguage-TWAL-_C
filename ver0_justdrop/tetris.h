#include <stdio.h>


struct block{
    int hight; // position of block in vertical line
    int width; // position of block in horizointal line
	int shape; // shape of block
};

int tetrix[25][12];


/* defined in tetrisfunc.c */
void init_tetrix();
struct block make_block(int shp);
void movement(struct block *blk, int dir);
void mark_shape(struct block block);
int isTouch();


/* defined in tetrisvisual.c */
void print_frame();
void print_tetrix();

