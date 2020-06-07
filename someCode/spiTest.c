#include<stdio.h>
void testPrint(char *arr, int n){
    printf("%c\n", arr[n]);
}
int main(){
    int n;
    char arr[8] ={"abcdefgh"};
    for(n=0; n<8; n++){
	testPrint(arr, n);
    }
/*    for(n=0; n<8; n++){
	printf("%c\n", arr[n]);
	}*/
    return 0;
}
