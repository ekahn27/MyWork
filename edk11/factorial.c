#include<stdio.h>
int factorial(int x){
    static int a;
    if(x>0){
	a= x*factorial(x-1);
	x--;
    }
    else if(x==0){
	return 1;
    }
    return a;
}

int main(){
    int x;
    
    printf("Enter a number to get its factorial\n");
    scanf("%d", &x);

    printf("%d", factorial(x));
    
    return 0;
}
