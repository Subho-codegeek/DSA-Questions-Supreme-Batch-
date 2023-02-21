#include <iostream>
using namespace std;

int main()
{
    int arr[] = {9, 5, 6, 3, 4, 2, 1, 7, 8, 2};
    int start = 0;
    int end = 9;
    while (start <= end)
    {
        cout << arr[start] << " " << arr[end] << " ";
        start++;
        end--;
    }

    return 0;
}