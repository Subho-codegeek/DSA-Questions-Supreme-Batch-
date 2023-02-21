#include <iostream>
using namespace std;

int main()
{
    int arr[] = {9, 5, 6, 3, 4, 2, 1, 7, 8, 2, 1};
    int start = 0;
    int end = 10;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}