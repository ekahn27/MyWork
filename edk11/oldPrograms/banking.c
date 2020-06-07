/*banking program w/ two accounts. Choose accout 1 or account 2 to interact with and then decide your account number and if you want to deposit or withdraw.  User can then choose to continue making transactions or stop and the program terminates. */
#include<stdio.h>
typedef struct bankAccount{//bank account structure with account number and balance
   int accNum;
   int balance;
}acc;
int main(){
   int a, b, c, d, e, f, g, h;
   int z= 1;
   char x, y;
   acc acc1, acc2; //creating two account structures
   acc1.balance=0; //initializing data in structures
   acc1.accNum=1;
   acc2.balance=0;
   acc2.accNum=2;
   while(z!=0){ /*how come this doesn't work if you say while(z=1)
		  loop lets user continue to withdraw/deposit money until they wish to stop*/
      printf("Please type %d or %d to access account %d or account %d\n", acc1.accNum, acc2.accNum, acc1.accNum, acc2.accNum);
      scanf("%d", &a);//choosing which account to interact with
      if(a==acc1.accNum) {
	 printf("Please enter an account number.\n");
	 scanf("%d", &b);//user enter account number for acc1
       acc1.accNum = b;
       printf("Enter d or w to deposit or withdraw from account %d?\n", b);
       b= getchar();//emptying input buffer so user can decide to deposit 'd' or withdraw 'w'
       scanf("%c", &x);
       if(x=='d'){
         printf("Please enter the amount you wish to deposit.\n");
	 scanf("%d", &c);
	 acc1.balance+=c;
        }
       else if(x=='w'){
         printf("Please enter the amount you wish to withdraw.\n");
         scanf("%d", &d);
         acc1.balance-=d;
       }
     }
      else if(a==acc2.accNum){ //accessing acc2
       printf("Please enter an account number.\n");
       scanf("%d", &e);
       acc2.accNum = e;
       printf("Enter d or w to deposit or withdraw from account %d.\n", e);
       e= getchar();
       scanf("%c", &y);
       if(y=='d'){
	 printf("Please enter the amount you wish to deposit.\n");
	 scanf("%d", &f);
	 acc2.balance+=f;
       }
       else if(y=='w'){
	 printf("Please enter the amount you wish to withdraw\n");
	 scanf("%d", &g);
	 acc2.balance-=g;
       }
     }
      printf("%d: $%d\n%d: $%d\n", acc1.accNum, acc1.balance, acc2.accNum, acc2.balance); //printing out both accounts info
      printf("Enter 1 for another transaction or 0 to quit\n");
      scanf("%d", &z); //asks user if they want to continue and sets int z to 1 or 0 to satisfy while loop condition or terminate program
   }
  return 0;
}
