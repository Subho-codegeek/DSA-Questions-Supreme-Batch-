class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int i = 0;
        int j = i + 1;
        set<pair<int, int>> ans;
        sort(nums.begin(), nums.end());
        while (j < nums.size())
        {

            int diff = nums[j] - nums[i];

            if (diff == k)
            {
                ans.insert({nums[i], nums[j]});
                i++;
                j++;
            }
            if (diff > k)
            {
                i++;
            }
            if (diff < k)
            {
                j++;
            }
            if (i == j)
            {
                j++;
            }
        }
        return ans.size();
    }
};