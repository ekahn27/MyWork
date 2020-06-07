//check if string of letters are in alphabetical order
#include<stdio.h>
int main(){
    int x, y; //x begins as first char, y as second
//y value is passed to x and y takes the value of the next character
    int i;
    int stop=0;//if we find a letter that is less, stop is set to true and loop ends

    printf("Enter your letters to see if they are in alphabetical order\n");
    for(i=0; (y=getchar()) !='\n' && stop==0; i++){
		if(i==0){//used so we can get first and second char before comparing
			x=y;
		}
		else if(x>y){
			stop=1;
		}
			else{
			x=y;
		}
    }
    if(stop==0){
	printf("Alphabetical order");
    }
    else if(stop==1){
	printf("Not alphabetical order");
    }

    return 0;
}
