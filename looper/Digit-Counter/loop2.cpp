#include<iostream>
using namespace std;

int main(){
    int num;
    int count = 0;

    cout<<"Enter any number: ";
    cin>>num;

    if(num == 0){
        count = 1;
    }
    while(num != 0){
        num /= 10;
        count++;
    }
    cout<<"Total number of digits: "<<count;
}
