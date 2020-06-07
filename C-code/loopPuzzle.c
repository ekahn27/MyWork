#include<stdio.h>

void printRecurse(int num){
    if(num == 0){return;}

    printf("%d\n", num);
    printRecurse(num-1);
}
int main(){
    printRecurse(10);
}
