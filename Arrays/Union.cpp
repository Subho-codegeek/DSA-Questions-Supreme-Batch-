#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr1[] = {2, 4, 6, 1};
    int arr2[] = {1, 3, 7};
    vector<int> arr3;
    for (int i = 0; i < 4; i++)
    {
        arr3.push_back(arr1[i]);
    }
    for (int j = 0; j < 3; j++)
    {
        arr3.push_back(arr2[j]);
    }
    for (int k = 0; k < arr3.size(); k++)
    {
        cout << arr3[k] << " ";
    }
    return 0;
}