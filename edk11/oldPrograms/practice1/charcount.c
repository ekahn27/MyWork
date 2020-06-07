//counts number of characters in a line
#include<stdio.h>
int main(){
   int nc;
   for(nc=0; getchar() != '\n'; nc++)
      ;
   printf("Number of characters: %d", nc);
   return 0;
}
