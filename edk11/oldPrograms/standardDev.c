/* Calculates standard deviation of a set of numbers input by user*/
#include<stdio.h>
#include<math.h>
int main(){
   int n, i;
   double total=0;
   double total2=0;
   double meanSqr;
   double variance;
   double standDev;
   
   printf("Please input the number of data points in your set\n");
   scanf("%d", &n); //finds number of data points for calculating mean and variance
   double arr[n];  //creates an array of size n to store data points
   printf("Please input your %d numbers one at a time\n", n);

   for(i=0; i<n; i++) { //puts users numbers into the array and adds up the numbers
      scanf("%lf", &arr[i]);
      total+=arr[i]; //summation later used to calculate mean squared
      total2+= (arr[i]*arr[i]); //used to calculate sumation of x squared
   }
   meanSqr= (total/n)*(total/n);
   variance= (total2-(meanSqr*n))/(n-1);
   standDev= sqrt(variance);

   printf("Standard deviation: %f\n", standDev);

   return 0;
}
