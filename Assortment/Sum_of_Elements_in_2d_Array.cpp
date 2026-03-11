#include<iostream>
using namespace std;

int main(){
    int rows, columns;
    cout << "Enter the array's row size: ";
    cin >> rows;

    cout << "Enter the array's column size: ";
    cin >> columns;

    int arr[rows][columns];
    cout<<"Enter array's elements"<<endl;
    for(int i = 0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout<<"arr["<<i<<"]["<<j<<"]=";
            cin>>arr[i][j];
        }
    } 

   int row, col;
    int sum = 0;

    // Row
    cout << "Enter row number: ";
    cin >> row;

    cout << "Row elements: ";
    for(int j = 0; j < columns; j++)
    {
        cout << arr[row-1][j] << " ";
        sum = sum + arr[row-1][j];
    }

    cout << "\nRow sum = " << sum << endl;

    // Column
    sum = 0;
    cout << "Enter column number: ";    
    cin >> col;

    cout << "Column elements: ";
    for(int i = 0; i < rows; i++)
    {
        cout << arr[i][col-1] << " ";
        sum = sum + arr[i][col-1];
    }

    cout << "\nColumn sum = " << sum;

}