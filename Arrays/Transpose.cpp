#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {5, 6, 7, 8}, {2, 4, 6, 8}};
    int arr1[4][4];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr1[i][j] = arr[j][i];
        }
    }
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int k = 0; k < 4; k++)
    {
        for (int l = 0; l < 4; l++)
        {
            cout << arr1[k][l] << " ";
        }
        cout << endl;
    }

    return 0;
}