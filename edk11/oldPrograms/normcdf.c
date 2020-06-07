//Normal CDF program Riemann Sum: Eric Kahn, Tommy McBride
#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793238462643383279
#define e 2.718281828459045235360287471352
int main(){
   double M; //mean
   double S; //standard deviation
   double upper; //upper bound
   double lower; //lower bound
   long double y, x;
   double sum= 0;//sum of y coordinates of each rectangle under curve
   long double cdf;//final answer
   int i;
   int iRes=10000000;//used to change delta x and number of rectangles under curve

   printf("What is the mean?\n");
   scanf("%lf", &M);
   printf("What is the standard deviation?\n");
   scanf("%lf", &S);
   printf("What is your lower bound?\n");
   scanf("%lf", &lower);
   printf("What is your upper bound?\n");
   scanf("%lf", &upper);

   x=(lower+0.5*((upper-lower)/iRes));//sets initial position of x (center left or right)
   for(i=0; i<(iRes-1); i++){
      y= (1/(sqrt(2*PI*S*S)))*(pow(e,((-pow((x-M),2))/(2*S*S))));
      sum+=y;
      x+=(upper-lower)/iRes;
   }
   cdf= sum*((upper-lower)/iRes);
   printf("Reimmann Sum Normalcdf: %20.19Lf", cdf);
   return 0;
}
