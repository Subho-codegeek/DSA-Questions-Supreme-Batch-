#include <iostream>
using namespace std;

int count0(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            count += 1;
        }
    }
    return count;
}

int count1(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            count += 1;
        }
    }
    return count;
}

int main()
{
    int arr[] = {0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0};
    cout << "Number of 0: " << count0(arr, 11) << endl;
    cout << "Number of 1: " << count1(arr, 11) << endl;

    return 0;
}