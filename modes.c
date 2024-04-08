#include <stdio.h>
#include <stdlib.h>

static char bar[] = "======================================="
		    "======================================>";
#define UP 'k'
#define DOWN 'j'
#define RIGHT 'l'
#define LEFT 'h'
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
// Add Navigation, Write, and Select Mode.

void mv_up(unsigned int *x, unsigned int *y, line **a, dNode **b);
void mv_down(unsigned int *x, unsigned int *y, line **a, dNode **b);
void mv_right(unsigned int *x, dNode **b); 
void mv_left(unsigned int *x, dNode **b);

void mv_up(unsigned int *x, unsigned int *y, line **a, dNode **b) {
	if((*a)->prevline==NULL) return; //if at highest position, end
	*a=(*a)->prevline;
	unsigned int i=1;
	*b=(*a)->start;
	while(((*b)->next)->next!=NULL && i<(*x)) { // double next to not move into a \n char
		*(b)=*(b)->next;	
		i++;
	}
	if(i<x) *x=i; // if current line size < x position, update x
	gotoxy(*x,++(*y));
}

void mv_down(unsigned int *x, unsigned int *y, line **a, dNode **b) {
	if((*a)->nextline==NULL) return; //if at highest position, end
	*a=(*a)->nextline;
	unsigned int i=1;
	*b=(*a)->start;
	while(((*b)->next)->next!=NULL && i<(*x)) { // double next to not move into a \n char
		(*b)=(*b)->next;	
		i++;
	}
	if(i<x) *x=i; // if current line size < x position, update x
	gotoxy(*x,--(*y));
}

void mv_right(unsigned int *x, dNode **b) {
	if((*(b)->next)->next==NULL) return;
	*b=*(b)->next;
	printf("\033[1C");
	(*x)++;
}

void mv_left(unsigned int *x, dNode **b) {
	if((*(b)->prev)->prev==NULL) return;
	*b=*(b)->prev;
	printf("\033[1D");
	(*x)++;
}
