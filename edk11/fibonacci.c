//printing fibonacci sequence w/o recursion from user input of how many nums
#include<stdio.h>
int main(){
    int num;
    int init= 0;
    int init2= 1;
    int i;
    int temp;
    
    printf("How many fibonaccio numbers would you like?\n");
    scanf("%d", &num);
    for(i=0; i<num; i++){
	printf("%d ", init);
	temp= init;
	init= init2;
	init2+= temp;
    }

    return 0;
}
