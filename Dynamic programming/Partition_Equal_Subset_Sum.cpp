class Solution
{
public:
    bool solveUsingRec(vector<int> &nums, int index, int target)
    {
        // bc
        if (index >= nums.size())
            return 0;
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;

        int include = solveUsingRec(nums, index + 1, target - nums[index]);
        int exclude = solveUsingRec(nums, index + 1, target);

        return (include || exclude);
    }

    bool solveUsingMemo(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
    {
        // bc
        if (index >= nums.size())
            return 0;
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        int include = solveUsingMemo(nums, index + 1, target - nums[index], dp);
        int exclude = solveUsingMemo(nums, index + 1, target, dp);

        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool solveUsingTabulation(vector<int> &nums, int index, int target)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                bool include = 0;
                if (t - nums[index] >= 0)
                    include = dp[index + 1][t - nums[index]];

                bool exclude = dp[index + 1][t];

                dp[index][t] = (include || exclude);
            }
        }

        return dp[0][target];
    }

    bool solveUsingTabulationSO(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[0] = 1;
        next[0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                bool include = 0;
                if (t - nums[index] >= 0)
                    include = next[t - nums[index]];

                bool exclude = next[t];

                curr[t] = (include || exclude);
            }
            next = curr;
        }

        return next[target];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        int target = sum / 2;
        int index = 0;
        // int ans = solveUsingRec(nums,index,target);
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        int ans = solveUsingTabulation(nums, index, target);
        return ans;
    }
};