#include <iostream>
using namespace std;

void solve(string &str, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(str[start], str[end]);
    solve(str, start + 1, end - 1);
}
int main()
{
    string str = "abcdefghijkl";
    int start = 0;
    int end = str.length() - 1;
    solve(str, start, end);
    cout << str << endl;
    return 0;
}