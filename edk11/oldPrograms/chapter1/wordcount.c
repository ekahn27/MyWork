#include<stdio.h>
int main(){
   int c, nl, nw, nc, inword;
   inword= nw= nc= nl= 0;
   while((c=getchar()) != 48){ //ASCII value of 0 is 48
      ++nc;
      if(c=='\n'){
	 ++nl;
      }
      if(c== ' ' || c== '\n' || c=='\t'){
	 inword= 0;
      }
      else if(inword == 0){
	 ++nw;
	 inword= 1;
      }
//      printf("character: %d\nnew line: %d\n new word: %d\n new character: %d\n", c, nl, nw, nc);
   }
   printf("new line: %d\n new word: %d\n new character: %d\n", nl, nw, nc);
   
   return 0;
}
