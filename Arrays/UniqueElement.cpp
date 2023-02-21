#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 4, 2, 1, 3, 6, 5, 5, 6, 4};
    int ans = 0;
    for (int i = 0; i < 11; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans << endl;
    return 0;
}