#include <iostream>
using namespace std;
#include <vector>
int main()
{
    int arr[5][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {5, 6, 7, 8}, {2, 4, 6, 8}, {1, 4, 9, 6}};
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << endl;
    }

    return 0;
}