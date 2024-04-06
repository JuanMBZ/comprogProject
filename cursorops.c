#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char bar[] = "======================================="
		    "======================================>";
#define up() printf("\033[1A");
#define down() printf("\033[1B");
#define right() printf("\033[1C");
#define left() printf("\033[1D");
#define clear() printf("\033[2J");

int main() {
	int i;
	char dummy[100], direction;
	
	printf("[%s]\n[%s]\r", bar, bar);
	fflush(stdout);
	system("stty raw"); // reads stdin without the need for newline
	system("stty -echo"); // turns of echo
	while((direction=getchar())!='i') {
		switch(direction) {
			case 'k': up(); break;
			case 'j': down(); break;
			case 'l': right(); break;
			case 'h': left(); break;
		}
	}
	system("stty -raw");
	system("stty echo");
	printf("here\n\n");
	return 0;
}

