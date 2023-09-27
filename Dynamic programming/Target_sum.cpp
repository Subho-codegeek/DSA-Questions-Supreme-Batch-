class Solution
{
public:
    int solve(vector<int> &nums, int target, int i)
    {
        if (i == nums.size())
            return target == 0 ? 1 : 0;

        int plus = solve(nums, target + nums[i], i + 1);
        int minus = solve(nums, target - nums[i], i + 1);
        return plus + minus;
    }

    int solveUsingMemo(vector<int> &nums, int target, int i, map<pair<int, int>, int> &dp)
    {
        if (i == nums.size())
            return target == 0 ? 1 : 0;
        if (dp.find({i, target}) != dp.end())
        {
            return dp[{i, target}];
        }
        int plus = solveUsingMemo(nums, target + nums[i], i + 1, dp);
        int minus = solveUsingMemo(nums, target - nums[i], i + 1, dp);
        dp[{i, target}] = plus + minus;
        return dp[{i, target}];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        map<pair<int, int>, int> dp;
        // return solve(nums,target,0);
        return solveUsingMemo(nums, target, 0, dp);
    }
};