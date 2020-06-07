//Letter received 1/2/19 from bonnie.  Encrypted with prime numbers where the first prime number (2) corresponds to A, the second prime number (3) corresponds to B, etc
#include<stdio.h>
int main(){
    int num=1;
    int i= -1;
    
    int arr[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    char letters[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    while(num != 0){
	i= -1;
	printf("Enter the number = ");
	scanf("%d", &num);
	do{
	    i++;
	    if(num == arr[i]){
		printf("%c\n", letters[i]);
	    }

	}while(num != arr[i]);
    }
    return 0;
}
