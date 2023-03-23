// using recursion

#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{

    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    // copy values in left
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    // copy values in right
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;
        }
    }

    // ab bacha kucha values ko vi copy karado main array me
    while (leftIndex < len1)
    {
        arr[mainIndex++] = left[leftIndex++];
    }
    while (rightIndex < len2)
    {
        arr[mainIndex++] = right[rightIndex++];
    }
}

void mergeSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // left wala part sort karo recursion se
    mergeSort(arr, s, mid);

    // right wala part sort karo recursion se
    mergeSort(arr, mid + 1, e);

    // merge kardo
    merge(arr, s, e);
}

int main()
{
    int arr[] = {8, 4, 3, 1, 20, 50, 30};
    int n = 7;
    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}