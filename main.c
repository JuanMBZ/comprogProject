#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"
#include "modes.h"

#define clear() printf("\033[2J")
#define cursor_start() printf("\033[H")
#define cursorto(x,y) printf("\033[%u;%uH", (y), (x))
#define UP 'k'
#define DOWN 'j'
#define RIGHT 'l'
#define LEFT 'h'
#define INSERT 'i'
//Add code/ops for reading and writing to file here
//Add terminal scrolling up and down, terminal resizing, showing info at bottom of terminal
void init_terminal(line **a, dNode **b, FILE *in);//prepares terminal

int main(int argc, char *argv[]) {
	unsigned int x=1, y=1, lastx=x; // cursor position x=col, y=row 
	char command;
	line *pos_line;
	dNode *pos_col;
	FILE *fiptr;
	if(argc!=2) {
		printf("Too many/few arguments.\n");
		return -1;
	}
	fiptr=fopen(argv[1], "r");
	
	init_terminal(&pos_line, &pos_col, fiptr);
	system("stty raw"); // reads stdin without the need for newline
	system("stty -echo"); // turns of echo
	while((command=getchar())!='e') {
		switch(command) { //Uses linux terminal control sequences to move cursor
			case UP:
				x=lastx;// saves last position of x so it can jump 
					// to shorter lines without changing later
				mv_up(&x, &y, &pos_line, &pos_col);
				cursorto(x,y);
				break;
			case DOWN:
				x=lastx;
				mv_down(&x, &y, &pos_line, &pos_col);
				cursorto(x,y);
				break;
			case RIGHT: 
				if(x>pos_line->size) x=pos_line->size;
				mv_right(&x, &pos_col);
				lastx=x;
				break;
			case LEFT:
				if(x>pos_line->size) x=pos_line->size;
				mv_left(&x, &pos_col);
				lastx=x;
				break;
			case INSERT:

		}
	}
	system("stty cooked"); //turn them back on
	system("stty echo");

	cursorto(1,45);
	printf("Current char after finishing: %c\n", pos_col->ch); 
	printf("Final Position: %u %u\n", x, y);
	return 0;
}

void init_terminal(line **a, dNode **b, FILE *in) {
	clear();
	cursor_start();
	*a=createList(in);
	*b=(*a)->start;
	display(*a);
	cursor_start();
}
