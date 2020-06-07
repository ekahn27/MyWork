#include<stdio.h>
int main(){
   float fahr, celsius;
   int lower= 0;
   int upper= 300;
   int step= 20;

   fahr= lower;
   printf("Celsius to Fahrenheit table\n");
   while(celsius<= upper){
      fahr= ((9/5) * celsius) +32;
      printf("celsius: %4.0f farhrenheit: %6.1f\n", celsius, fahr);
      celsius+=step;
      }
   return 0;
}
