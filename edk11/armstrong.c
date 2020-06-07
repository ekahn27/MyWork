#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int i, a, b;
    int n=0;
    char x;
    int count;
    int *num= (int*) calloc(10, sizeof(int));
    int sumA=0;
    int sumB=0;

    printf("Enter a positve integer to check if it's an Armstrong number\n");
    for(i=0; (x=getchar()) != '\n'; i++){
	num[i]=(x-'0');
	count++;
    }
    for(a=0; a<count; a++){//armstrong num calculated
	sumA+= pow(num[a],count);
    }
    for(b=count; b>0; b--){
	sumB+= num[b-1]*pow(10,n);
	n++;
    }
    if(sumA== sumB){
	printf("This is an Armstrong number");
    }
    else{
	printf("This is Not an Armstrong number");
	}

    free(num);
    return 0;
}
