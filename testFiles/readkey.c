#include <stdio.h>
#include <stdlib.h>

char readkey();

int main() {
	char input, dummy[50];
	
	for(;;) {
		printf("Type Input:");
		fflush(stdout);
		input=readkey();
		printf("\nInput read: %c", input);
		fflush(stdout);
		printf("\nExit?(ctrl-c)");
		scanf("%s", dummy);
		input=getchar();
	}

	return 0;
}

char readkey() {
	char input;
	system("stty raw"); //read input without needing newline
	system("stty -echo"); //stop echo
	input=getchar();
	system("stty echo");
	system("stty -raw");
	return input;
}
