#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int index = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    int largest = index;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        index = largest;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n--]);
        heapify(arr, n, 1);
    }
}

int main()
{
    //  heapify, buildheap, heapsort
    int arr[] = {-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    buildHeap(arr, n);

    cout << "printint the heap " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << endl
         << "printint the heap " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}