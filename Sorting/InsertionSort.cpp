#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{10, 1, 7, 6, 14, 9};
    int n = arr.size();

    // insertion sort
    for (int round = 1; round < n; round++)
    {
        // step A - fetch
        int val = arr[round];
        // step B - compare
        int j = round - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > val)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // rukna hei
                break;
            }
        }
        // step D - Copy
        arr[j + 1] = val;
    }
    // printing
    return 0;
}