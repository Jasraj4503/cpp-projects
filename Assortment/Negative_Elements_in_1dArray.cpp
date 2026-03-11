#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    
    cout<<"Negative elements fron an array: ";
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < 0){
            cout<<arr[i]<<",";
        }
    }


    
}