#include <iostream>
using namespace std;

// Base Class (Inheritance + Polymorphism)
class StackOperations
{
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void top() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;
};

// Derived Class
class Stack : public StackOperations
{
private:
    int arr[5];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }

    void push(int value) override
    {
        if (topIndex == 4)
        {
            cout << "Stack is Full!" << endl;
        }
        else
        {
            topIndex++;
            arr[topIndex] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    void pop() override
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << arr[topIndex] << " removed from stack." << endl;
            topIndex--;
        }
    }

    void top() override
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "Top Element: " << arr[topIndex] << endl;
        }
    }

    void isEmpty() override
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty." << endl;
        }
        else
        {
            cout << "Stack is Not Empty." << endl;
        }
    }

    void isFull() override
    {
        if (topIndex == 4)
        {
            cout << "Stack is Full." << endl;
        }
        else
        {
            cout << "Stack is Not Full." << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Top Element" << endl;
        cout << "4. Check if Stack is Empty" << endl;
        cout << "5. Check if Stack is Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.top();
            break;

        case 4:
            s.isEmpty();
            break;

        case 5:
            s.isFull();
            break;

        case 6:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}