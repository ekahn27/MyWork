#include<stdio.h>

int solve5(){
	for(int num= 20; ; num += 20){
		int isAns= 1;
		int div= 2;
		while(isAns && div <= 19){
			if(num % div != 0){
				isAns= 0;
			}
			if(div == 19 && isAns){
				return num;
			}
			div++;
		}
	}
}

int main(){
	int answer= solve5();
	printf("Answer to 5: %d\n", answer);

	return 0;
}

