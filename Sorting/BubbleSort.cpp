#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{10, 1, 7, 6, 14, 9};

    int n = arr.size();
    // bubble sort
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; n++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
    return 0;
}