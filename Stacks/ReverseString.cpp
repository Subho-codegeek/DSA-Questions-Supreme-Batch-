#include <iostream>
#include <stack>
using namespace std;

void reverse(stack<char> &s, string st)
{
    for (int i = 0; i < st.length(); i++)
    {
        s.push(st[i]);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<char> s;
    string st = "subhamay";
    reverse(s, st);
    return 0;
}