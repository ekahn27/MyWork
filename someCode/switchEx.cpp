#include<iostream>
using namespace std;
int main(){
    int num;
    cout <<"Enter your grade to the nearest 10%" <<endl;
    cin>>num;

    switch(num){
    case 60:
	cout<<"D"<<endl;
	break;
    case 70:
	cout<<"C"<<endl;
	break;
    case 80:
	cout<<"B"<<endl;
	break;
    case 90:
	cout<<"A"<<endl;
	break;
    default:
	cout<<"Fail"<<endl;
	break;
    }

    return 0;
}
