#include <iostream>
using namespace std;

int main()
{
    int row, column;
    cout << "Enter the array's row size: ";
    cin >> row;

    cout << "Enter the array's column size: ";
    cin >> column;

    int arr[row][column];
    cout<<"Enter array's elements"<<endl;
    for(int i = 0; i<row; i++){
        for(int j=0; j<column; j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>arr[i][j];
        }
    } 
    
    int max = arr[0][0]; 
    for(int i = 0; i<row; i++){
        for(int j=0; j<column; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
    } 
    cout<<"The largest element is: "<<max;
}