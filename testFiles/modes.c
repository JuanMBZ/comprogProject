#include <stdio.h>
#include <stdlib.h>

static char bar[] = "======================================="
		    "======================================>";
#define clear() printf("\033[2J");
#define UP 'k'
#define DOWN 'j'
#define RIGHT 'l'
#define LEFT 'h'
// Add Navigation, Write, and Select Mode.


int main() {
	int i;
	char direction;
	
	clear();
	printf("\033[H");
	printf("[%s]\n[%s]\r", bar, bar);
	fflush(stdout);
	system("stty raw"); // reads stdin without the need for newline
	system("stty -echo"); // turns of echo
	while((direction=getchar())!='i') {
		switch(direction) { //Uses linux terminal control sequences to move cursor
			case UP: printf("\033[1A"); break;
			case DOWN: printf("\033[1B"); break;
			case RIGHT: printf("\033[1C"); break;
			case LEFT: printf("\033[1D"); break;
		}
	}
	system("stty -raw");
	system("stty echo");
	printf("here\n\n");
	return 0;
}

