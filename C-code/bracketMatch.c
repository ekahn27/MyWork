#include <stdio.h>
#include "LL.h"

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("No filename given\n");
		return 0;
	}
	char *filename= argv[1];
	printf("filename is: %s\n\n", filename);

	FILE *file= fopen(filename, "r");
	if(file){//file name is valid
		char c;
		node_t *LL= initNode();
		while((c = getc(file)) != EOF){
			//putchar(c);//testing opening file
			switch(c){
				case '(':
					LL->val= '(';
					appendLL(LL, initNode());
					break;
				case '[':
					LL->val= '[';
					appendLL(LL, initNode());
					break;
				case '{':
					LL->val= '{';
					appendLL(LL, initNode());
					break;
				case ')':
					break;
				case ']':
					break;
				case '}':
					break;
				default:
					break;
			}
		}
		fclose(file);
	}
	else{//file name not valid
		printf("Not valid file name\n");
	}

	return 0;
}
