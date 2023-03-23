class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // for (int j=0; j<n; j++){
        //     int index=nums[j];
        //     if(nums[j]!=nums[index]){
        //         swap(nums[j],nums[index]);
        //     }
        // }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }

        return n;
    }
};