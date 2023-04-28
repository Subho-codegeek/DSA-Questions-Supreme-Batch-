#include <iostream>
#include <stack>
using namespace std;

void findMiddle(stack<int> &s, int totalSize)
{
    if (s.size() == (totalSize / 2) + 1)
    {
        cout << s.top() << endl;
        return;
    }

    int top = s.top();
    s.pop();

    // rec call
    findMiddle(s, 7);

    // bt
    s.push(top);
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
    s.push(70);

    findMiddle(s, 7);

    return 0;
}