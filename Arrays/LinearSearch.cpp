#include <iostream>
using namespace std;

int linearSearch(int arr[], int target)
{
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {9, 5, 6, 3, 4, 2, 1};
    int target = 6;
    cout << "Target fount at " << linearSearch(arr, target) << endl;
    return 0;
}