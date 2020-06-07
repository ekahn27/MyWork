#include<stdio.h>
int main(){
   int c;
   while((c=getchar()) != 48){
      putchar(c);
   }
   return 0;
}
