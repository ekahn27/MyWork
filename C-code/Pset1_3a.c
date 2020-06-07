#include <stdio.h>
int fib(int n) {
    int i, f_n;
    int f_n_2;
    int f_n_1 = 1;
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    for (i = 1; i < n; ++i){
        f_n = f_n_1 + f_n_2; // F(n) = F(n-1) + F(n-2)
        f_n_2 = f_n_1;
        f_n_1 = f_n;
    }
    return f_n;
}

int main(){
   int a= fib(5);
   printf("%d\n", a);
   return 0;
}
