// using recursion

#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{

    // step1
    int pivotIndex = s;
    int pivotElement = arr[s];

    // step2
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (pivotElement >= arr[i])
        {
            count += 1;
        }
    }

    // putting the pivotElement in right place
    int rightIndex = s + count;
    swap(arr[rightIndex], arr[pivotIndex]);
    pivotIndex = rightIndex;

    // step3 -- check if all the elements in left are smaller and right are greater than pivotelement
    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex])
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // partitioning
    int p = partition(arr, s, e);

    // left
    quickSort(arr, s, p - 1);

    // right
    quickSort(arr, p + 1, e);
}
int main()
{

    int arr[] = {8, 4, 3, 1, 20, 50, 30};
    int n = 7;
    int s = 0;
    int e = n - 1;

    quickSort(arr, s, e);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}