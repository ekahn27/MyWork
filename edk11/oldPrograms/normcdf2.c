//Version 2:Normal CDF program Monte Carlo: Eric Kahn, Tommy McBride
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define PI 3.14159265358979
#define e 2.7182818284590452
int main(){
   double M; //mean
   double S; //standard deviation
   double upper; //upper bound
   double lower; //lower bound
   double upperY; //y coordinate of upper bound
   double lowerY; //y coordinate of lower bound
   double maxY; //y coordinate of mean (max on curve)
   double y, x;
   double points=0;//actual number of points under the curve
   double p;//percentage of points under the curve
   double cdf;//final answer
   int i;
   double iRes=10000000;//used to change delta x and number of rectangles under curve

   srand(time(0));
   
   printf("What is the mean?\n");
   scanf("%lf", &M);
   printf("What is the standard deviation?\n");
   scanf("%lf", &S);
   printf("What is your lower bound?\n");
   scanf("%lf", &lower);
   printf("What is your upper bound?\n");
   scanf("%lf", &upper);

   upperY= (1/(sqrt(2*PI*S*S)))*(pow(e,((-pow((upper-M),2))/(2*S*S))));
   lowerY= (1/(sqrt(2*PI*S*S)))*(pow(e,((-pow((lower-M),2))/(2*S*S))));//upperY and lowerY used when bounds are both greater or less then mean
   maxY= (1/(sqrt(2*PI*S*S)));//used when bounds straddle the mean
   
   if(M>=lower && M<=upper){
      for(i=0; i<iRes; i++){
	 x= ((float)rand()/(float)RAND_MAX)*(upper-lower)+lower;//x is set equal to a random floating point number
	 y= ((float)rand()/(float)RAND_MAX)*(maxY);//y is set equal to a random floating point number
//ABOVE 2 lines: (float)rand() is random floating point(eg: 2.) divided by the max random number that can be generated to get a float [0,1]
//then multiplied by a number to set the interval and the addition shifts the interval
	 if(y< ((1/(sqrt(2*PI*S*S)))*(pow(e,((-pow((x-M),2))/(2*S*S)))))){
	    points+=1;
	 }
      }
      p= points/iRes;
      cdf= p*(upper-lower)*maxY;
   }
   else if(M>lower && M>upper){
      for(i=0; i<iRes; i++){
	 x= ((float)rand()/(float)RAND_MAX)*(upper-lower)+lower;
	 y= ((float)rand()/(float)RAND_MAX)*(upperY);
	 if(y< ((1/(sqrt(2*PI*S*S)))*(pow(e,((-pow((x-M),2))/(2*S*S)))))){
	    points+=1;
	 }
      }
      p= points/iRes;
      cdf= p*(upper-lower)*upperY;
   }
   else if(M<lower && M<upper){
      for(i=0; i<iRes; i++){
	 x= ((float)rand()/(float)RAND_MAX)*(upper-lower)+lower;
	 y= ((float)rand()/(float)RAND_MAX)*(lowerY);
	 if(y< ((1/(sqrt(2*PI*S*S)))*(pow(e,((-pow((x-M),2))/(2*S*S)))))){
	    points+=1;
	 }
      }
      p= points/iRes;
      cdf= p*(upper-lower)*lowerY;
   }
   printf("Monte Carlo Normalcdf: %20.19lf", cdf);
   return 0;
}
