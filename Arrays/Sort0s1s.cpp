#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {1, 0, 1, 0, 1, 1, 1, 0, 0};
    int i = 0;
    int start = 0;
    int end = 9 - 1;
    while (i < end)
    {
        if (arr[i] == 0)
        {
            swap(arr[start], arr[i]);
            i++;
        }
        if (arr[i] == 1)
        {
            swap(arr[i], arr[end]);
            end--;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}