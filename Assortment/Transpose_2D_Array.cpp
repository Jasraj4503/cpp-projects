#include<iostream>
using namespace std;

int main(){
    int row, column;

    cout<<"Enter the number of rows and columns: ";
    cin>>row>>column;

    int matrix[10][10], transpose[10][10];

    cout<<"Enter array's elements"<<endl;
    for(int i = 0; i<row; i++){
        for(int j=0; j<column; j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>matrix[i][j];
        }
    } 

    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            transpose[j][i] = matrix[i][j];
        }
    }

    cout<<"The transpose matrix of an array: "<<endl;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}