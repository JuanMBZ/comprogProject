#include <stdio.h>
#include <stdlib.h>

#define cursorto(x,y) printf("\033[%u;%uH", (y), (x))
// Add Navigation, Write, and Select Mode.
// Functions for navigation
// Possible Additions: Moving word by word, Moving a specified number of times in one direction

void mv_up(unsigned int *x, unsigned int *y, line **a, dNode **b);
void mv_down(unsigned int *x, unsigned int *y, line **a, dNode **b);
void mv_right(unsigned int *x, dNode **b); 
void mv_left(unsigned int *x, dNode **b);

void mv_up(unsigned int *x, unsigned int *y, line **a, dNode **b) {
	if((*a)->prev_line==NULL) return; //if at highest position, end
	*a=(*a)->prev_line;
	unsigned int i=1;
	*b=(*a)->start;
	while(((*b)->next)->next!=NULL && i<(*x)) { // double next to not move into a \n char
		(*b)=(*b)->next;	
		i++;
	}
	if(i<*(x)) *x=i; // if current line size < x position, update x
	*y-=1;
}

void mv_down(unsigned int *x, unsigned int *y, line **a, dNode **b) {
	if((*a)->next_line==NULL) return; //if at highest position, end
	*a=(*a)->next_line;
	unsigned int i=1;
	*b=(*a)->start;
	while(((*b)->next)->next!=NULL && i<(*x)) { // double next to not move into a \n char
		(*b)=(*b)->next;	
		i++;
	}
	if(i<*(x)) *x=i; // if current line size < x position, update x
	*y+=1;
}

void mv_right(unsigned int *x, dNode **b) {
	if(((*b)->next)->next==NULL) return;
	*b=(*b)->next;
	printf("\033[1C");//move cursor right
	(*x)++;
}

void mv_left(unsigned int *x, dNode **b) {
	if(((*b)->prev)->prev==NULL) return;
	*b=(*b)->prev;
	printf("\033[1D");//move cursor left
	(*x)--;
}
