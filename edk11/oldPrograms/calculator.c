#include<stdio.h>
int main(){
   char operation;
   float x, y;
   int a=1;
   char on;
   while(on != 'z' && on != 'Z'){
      do{
	 printf("Input an operation +, -, *, /\n");
	 scanf("%c", &operation);
	 getchar();
	 if(operation == '+' || operation=='-' || operation=='*' || operation=='/'){
	    a=0;
	 }
      }while(a==1);
      printf("Input a number\n");
      scanf("%f", &x);
      printf("Input a second number\n");
      scanf("%f", &y);
      switch(operation){
      case'+':
	 printf("%f\n", x+y);
	 break;
      case'-':
	 printf("%f\n", x-y);
	 break;
      case'*':
	 printf("%f\n", x*y);
	 break;
      case'/':
	 printf("%f\n", x/y);
	 break;
      default:
	 printf("Not valid\n");
      }
      printf("Enter 'z' to stop calculations or any other letter to continue\n");
      getchar();
      scanf("%c", &on);
      getchar();
   }
   return 0;
}
