/*
Starting in the top left corner of a 2×2 grid, and only being able to move to
the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/
#include<stdio.h>

int problem15(int x, int y, int *size){
	if(x == *size && y == *size){
		return 1;
	}
	int doSubtract= 0;
	int totalPaths= 0;
	if(x < *size){
		doSubtract= 1;
		x += 1;
		totalPaths += problem15(x, y, size);
	}
	if(y < *size){
		if(doSubtract){
			x -= 1;
		}
		y += 1;
		totalPaths += problem15(x, y, size);
	}
	return totalPaths;
}

int main(){
	int x= 0;
	int y= 0;
	for(int i=3; i <= 15; i++){
		int ans= problem15(x, y, &i);
		printf("Answer to problem 15 size %d is: %d\n", i, ans);
	}
	return 0;
}

