//Calculates the area of a cirlce
#include<stdio.h>
int main(){
  int rad;
  float pi = 3.14;
  float area;
  printf("Please input the radius of a circle\n");
  scanf("%d", &rad);
  area = (pi * rad * rad);
  printf("The area of your circle is %f", area);
  return 0;
  }
