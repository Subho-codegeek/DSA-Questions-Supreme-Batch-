class Solution
{
public:
    int oddOccurence(vector<int> nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        while (s < e)
        {
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                {
                    s = mid + 2;
                }
                else
                {
                    e = mid;
                }
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            mid = s + (e - s) / 2;
        }
        return nums[e];
    }
    int singleNonDuplicate(vector<int> &nums)
    {
        int ans = oddOccurence(nums);
        return ans;
    }
};