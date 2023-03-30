#include <iostream>
using namespace std;

void solve(string &str, int index, int &ans, char key)
{
    if (index >= str.length())
    {
        return;
    }
    if (str[index] == key)
    {
        ans = index;
    }
    solve(str, index + 1, ans, key);
}

int main()
{
    string str = "abcddedfg";
    int index = 0;
    int ans = -1;
    char key = 'd';
    solve(str, index, ans, key);
    cout << ans << endl;
    return 0;
}