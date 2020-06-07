//checks user number to see if it's prime
#include<stdio.h>
#include<math.h>
int main(){
    int x;
    float root;
    int i=2;
    int notPrime= 0;

    printf("Enter your number to check if it's prime\n");
    scanf("%d", &x);
    
    if(x<=1){
	printf("Not a prime number");
    }
    else{
	root= sqrt(x) +1;
	do{
	    if(x%i==0){
		notPrime=1;
	    }
	    else{
		i++;
	    }
	}while(notPrime==0 && i<=root);	
    }

    if(notPrime==0){
	printf("%d is prime", x);
    }
    else if(notPrime==1){
	printf("%d is not prime", x);
    }

    return 0;
}
