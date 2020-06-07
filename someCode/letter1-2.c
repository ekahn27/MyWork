//Updated version of file letter1.c to read whole word at once
#include<stdio.h>
#include<string.h>
int main(){
    int num=1;
    int i;
    int j;//location of where we are in array "word"
    
    int arr[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    char letters[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char word[20];

    printf("Enter word one number at a time\n");
    while( num >= 0){//whole program
	j=0;
	num=1;//need to re-enter loop below after each word is over
	while(num > 0){//word
	    i= -1;
	    scanf("%d", &num);
	    do{//letter
		i++;
		if(num == arr[i]){
		    word[j]= letters[i];
		    j++;
		}
	    }while(num != arr[i] && num != 0);
	}
	printf("%s\n\n", word);
	memset(&word[0],0, sizeof(word));//clear word array here
    }
    return 0;
}
