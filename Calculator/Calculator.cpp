#include <iostream>
using namespace std;

void Add(int x, int y)
{
    cout << "Addition of " << x << " and " << y << " is " << x + y << endl
         << endl;
}
void Sub(int x, int y)
{
    cout << "Subtraction of " << x << " and " << y << " is " << x - y << endl
         << endl;
}
void Mul(int x, int y)
{
    cout << "Multiplication of " << x << " and " << y << " is " << x * y << endl
         << endl;
}
void Div(int x, int y)
{
    cout << "Division of " << x << " and " << y << " is " << x / y << endl
         << endl;
}
void Mod(int x, int y)
{
    cout << "Modulus of " << x << " and " << y << " is " << x % y << endl
         << endl;
}

int main()
{
    int choice;
    int x, y;
    while (1)
    {
        cout << "------Calculation Menu-----" << endl;
        cout << "Press 1 for +" << endl;
        cout << "Press 2 for -" << endl;
        cout << "Press 3 for *" << endl;
        cout << "Press 4 for /" << endl;
        cout << "Press 5 for %" << endl;
        cout << "Press 0 for the exit" << endl;

        cout << "Enter your choice = ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "End your program" << endl;
            break;
        }
        switch (choice)
        {
        case 1:
            cout << "Enter your first value = ";
            cin >> x;

            cout << "Enter your second value = ";
            cin >> y;

            Add(x, y);
            break;
        case 2:
            cout << "Enter your first value = ";
            cin >> x;

            cout << "Enter your second value = ";
            cin >> y;

            Sub(x, y);
            break;

        case 3:
            cout << "Enter your first value = ";
            cin >> x;

            cout << "Enter your second value = ";
            cin >> y;

            Mul(x, y);
            break;
        case 4:
            cout << "Enter your first value = ";
            cin >> x;

            cout << "Enter your second value = ";
            cin >> y;

            Div(x, y);
            break;
        case 5:
            cout << "Enter your first value = ";
            cin >> x;

            cout << "Enter your second value = ";
            cin >> y;

            Mod(x, y);
            break;

        default:
            break;
        }
    }
}