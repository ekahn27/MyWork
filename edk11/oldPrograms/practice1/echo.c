//repeats from stdin
#include<stdio.h>
//#include<string.h>
int main(){
   int c;
   //int a;
   while((c=getchar()) != 48){ //48 is the ASCII value for the CHARACTER 0
      putchar(c);
   }
/*   a= sizeof(c);
     printf("%d", a);*/
   return 0;
}
