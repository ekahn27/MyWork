#include <stdio.h>
int main(int argc, char *argv[]){
	//char *arr[]= {"word", "1", "2"};
	//printf("%s\n", arr[0]);
	char myChar;
	char* charPtr= &myChar;
	if(*charPtr){
		printf("NULL\n");
	}
	*charPtr= 'a';
	if(*charPtr){
		printf("%c\n", myChar);
		printf("In 2nd if: %c\n", *charPtr);
	}

    return 0;
}
