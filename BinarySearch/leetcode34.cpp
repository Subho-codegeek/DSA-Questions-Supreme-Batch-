class Solution
{
public:
    int firstOccurence(vector<int> nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                e = mid - 1;
            }
            else if (target > nums[mid])
            {
                s = mid + 1;
            }
            else if (target < nums[mid])
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
    int lastOccurence(vector<int> nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (target > nums[mid])
            {
                s = mid + 1;
            }
            else if (target < nums[mid])
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result;
        int firstIndex = firstOccurence(nums, target);
        int lastIndex = lastOccurence(nums, target);
        result.push_back(firstIndex);
        result.push_back(lastIndex);
        return result;
    }
};