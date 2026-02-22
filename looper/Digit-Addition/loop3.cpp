#include <iostream>
using namespace std;

int main()
{
    int num;
    int sum = 0;

    cout << "Enter any number: ";
    cin >> num;
    int lastDigit = num % 10;
    
    while (num > 10)
    {
        num = num / 10;
    }
    int firstDigit = num;
    sum = firstDigit + lastDigit;
    cout << "The sum of the first and last digit: " << sum;
}