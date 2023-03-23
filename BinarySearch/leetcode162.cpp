class Solution
{
public:
    int peakIndex(vector<int> nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        while (s < e)
        {
            if (nums[mid] < nums[mid + 1] && mid < nums.size() - 1)
            {
                // right search
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }

        return e;
    }
    int findPeakElement(vector<int> &nums)
    {
        return peakIndex(nums);
    }
};