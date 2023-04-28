#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int top = s.top();
    s.pop();
    // rec call
    insertAtBottom(s, target);
    // bt
    s.push(top);
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    // rec call
    reverse(s);

    insertAtBottom(s, target);
}

int main()
{

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    reverse(s);

    cout << "Printing" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}