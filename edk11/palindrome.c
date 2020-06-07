//tells if characters forms a palindrome or not
#include<stdio.h>
#include<stdlib.h>
int main(){
    char *arr= (char*) calloc(20, sizeof(char));//memory to hold input
    int x;
    int i=0;
    int count=0;
    int a;
    int b=1;

    printf("Enter your number to check if it's a Palindrome\n");//characters are put into memory one at a time instead of one group
    for(i=0; (x=getchar()) != '\n'; i++){
	arr[i]= x;
	count++;//counts characters entered to know where to put end pointer
    }

    char *ptrB= arr;//ptr for beginning of mem
    char *ptrE= &arr[count-1];//ptr for end of mem

    for(i=0; i<count/2 && b==1; i++){//only need to check until pointers come together.  Odd-int/2== lower num ex:(5/2==2)
	if((*ptrB) != (*ptrE)){
	    b=0;//if values don't match loop can end
	}
	ptrB++;//in/decrementing pointers
	ptrE--;
    }
    
    if(b==1){//1 means true: palindrome
	printf("This is a palindrome");
    }
    else if(b==0){//0 is false: no palindorme, non-match found
	printf("This is not a palindrome");
	}
    
    free(arr);
    return 0;
}
