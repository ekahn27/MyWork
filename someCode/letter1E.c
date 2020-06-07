//encrypt a letter into code
//each letter corresponds to a prime number, A = 2, B=3, C=5, etc
#include<stdio.h>
int main(){
    int primes[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char word[26];
    char c;
    int i, j;

    printf("Enter your text\n");
    for(i=0; (c=getchar()) != '\n'; i++){
	if(c == ' '){
	    word[i]=' ';
	}
	else{
	    j=0;
	    while(c != letters[j]){
		j++;
	    }
	    word[i]=primes[j];
	}
    }
    printf("%s", word);
    return 0;
}
