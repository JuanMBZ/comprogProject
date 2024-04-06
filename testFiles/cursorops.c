#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "readkey.h"

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
	for(int i=77; i>=0; i--) {
		printf("[%s]\r", &bar[i]);
		fflush(stdout);
	}
	printf("\n[%s]", bar); 
	printf("\r     ");
	fflush(stdout);
	
	down();down();
	printf("here\n\n");

	return 0;
}
