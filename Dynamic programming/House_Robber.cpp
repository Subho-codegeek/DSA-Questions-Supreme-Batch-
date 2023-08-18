class Solution
{
public:
    int solveUsingMemo(vector<int> &nums, int i, vector<int> &dp)
    {

        if (i >= nums.size())
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int robAmt1 = nums[i] + solve(nums, i + 2, dp);
        int robAmt2 = 0 + solve(nums, i + 1, dp);

        dp[i] = max(robAmt1, robAmt2);
        return dp[i];
    }

    int solveUsingTabulation(vector<int> &nums, int n)
    {
        vector<int> dp(n + 2, 0);
        dp[0] = nums[0];

        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            if (i - 2 >= 0)
            {
                temp = dp[i - 2];
            }
            int include = nums[i] + temp;
            int exclude = 0 + dp[i - 1];

            dp[i] = max(include, exclude);
        }
        return dp[n];
    }

    int spaceOptimised(vector<int> &nums, int n)
    {

        int prev2 = 0;
        int prev1 = nums[0];
        int curr = 0;
        for (int i = 1; i <= n; i++)
        {
            int temp = 0;
            if (i - 2 >= 0)
            {
                temp = prev2;
            }
            int include = nums[i] + temp;
            int exclude = 0 + prev1;

            curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size() - 1;
        // vector<int> dp(n+2,-1);
        // int i=0;
        // return solveUsingMemo(nums,i,dp);
        // return solveUsingTabulation(nums,n);
        return spaceOptimised(nums, n);
    }
};