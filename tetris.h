#include <stdio.h>


struct block{
    int hight; // position of block in vertical line
    int width; // position of block in horizointal line
	int shape; // shape of block
}

int tetrix[21][11] ={0,};


/* defined in tetrisfunc.c */
void movement(struct block, int);



/* defined in tetrisvisual.c */
void print_frame();
void print_block();

