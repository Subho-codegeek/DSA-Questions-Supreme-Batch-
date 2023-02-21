#include <iostream>
using namespace std;

int main()
{
    int arr[] = {9, 5, 6, 3, 4, 2, 1};
    int max = arr[0];
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Max Number: " << max << endl;
    return 0;
}