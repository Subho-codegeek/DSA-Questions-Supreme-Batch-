#include <iostream>
using namespace std;

class stack
{
private:
    int *arr;
    int top;
    int size;

public:
    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            // space not available
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow, cant delete element" << endl;
        }
        else
        {
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "There is not element in Stack " << endl;
        }
        else
        {
            return arr[top];
        }
    }

    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack s(5);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.push(60);

    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Size of stack " << s.getSize() << endl;

    s.pop();
    return 0;
}