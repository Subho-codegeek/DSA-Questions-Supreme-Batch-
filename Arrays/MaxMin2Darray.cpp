#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int arr[5][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {5, 6, 7, 8}, {2, 4, 6, 8}, {1, 4, 9, 6}};
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    cout << "max: " << max;
    cout << "min: " << min;

    return 0;
}