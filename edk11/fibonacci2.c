//fibonacci sequence using recursion
#include<stdio.h>
void fibonacci(int num){
    static int x= 0;//static variables means they keep their previous value each iteration of the function
    static int y= 1;
    int z;
    
    if(num>0){
	printf("%d ", x);
	z= x;
	x= y;
	y+=z;
	fibonacci(num-1);
    }
}

int main(){
    int num;
    
    printf("How many fibonacci numbers would you like?\n");
    scanf("%d", &num);
    fibonacci(num);
    
    return 0;
}
