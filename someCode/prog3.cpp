#include<iostream>
using namespace std;
int main(){
    float x;
    float y;
    cout<<"Enter two numbers"<<endl;
    cin >>x >> y;
    //cout<< "Your numbers: " << x << " " << y <<endl;

    char op;
    cout<<"Enter an operation, +, -, *, /"<<endl;;
    cin>>op;

    float value;
    switch(op){
        case '+': value= x + y;
                  break;
        case '-': value= x - y;
                  break;
        case '*': value= x*y;
                  break;
        case '/': value= x/y;
                  break;
    }
    cout<< "Answer= " << value <<endl;
    return value;
}
