#include <stdio.h>
#define MAX_HIGHT 25
#define MAX_WIDTH 12

struct block{
    int hight; // position of block in vertical line
    int width; // position of block in horizointal line
	int shape; // shape of block
};

int tetrix[MAX_HIGHT][MAX_WIDTH];


/* defined in tetrisfunc.c */
void init_tetrix();
struct block make_block(int shp);
struct block movement(struct block blk, int dir);
void mark_shape(int matrix[][MAX_WIDTH],struct block block);
int isTouch(struct block);
//void rotation
void back_up_tetrix(int n, int matrix[][MAX_WIDTH]);
int isgameEnd();
/* defined in tetrisvisual.c */
void print_frame();
void print_tetrix();

