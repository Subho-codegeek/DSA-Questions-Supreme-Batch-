#include <iostream>
#include <vector>
using namespace std;

// leetocde solution

vector<int> intersection(vector<int> nums1, vector<int> nums2)
{
    vector<int> arr;
    int flag = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                nums2[j] = -1;
                for (int k = 0; k < arr.size(); k++)
                {
                    if (nums1[i] == arr[k])
                        flag = 1;
                }
                if (flag == 0)
                {
                    arr.push_back(nums1[i]);
                }
                flag = 0;
            }
        }
    }
    return arr;
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    intersection(nums1, nums2);
    return 0;
}