class Solution
{
public:
    int MOD = 1000000007;
    int solveUsingRec(int n, int k, int target)
    {
        // base case
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 && target != 0)
            return 0;
        if (n != 0 && target == 0)
            return 0;

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans += solveUsingRec(n - 1, k, target - i);
        }
        return ans;
    }

    int solveUsingMemo(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (n < 0)
            return 0;
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 && target != 0)
            return 0;
        if (n != 0 && target == 0)
            return 0;
        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }

        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            int recans = 0;
            if (target - i >= 0)
                recans = solveUsingMemo(n - 1, k, target - i, dp);
            ans = (ans % MOD + recans % MOD) % MOD;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }

    int solveUsingTabulation(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int index = 1; index <= n; index++)
        {
            for (int t = 1; t <= target; t++)
            {
                int ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    int recans = 0;
                    if (t - i >= 0)
                        recans = dp[index - 1][t - i];
                    ans = (ans % MOD + recans % MOD) % MOD;
                }
                dp[index][t] = ans;
            }
        }
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        int ans = solveUsingTabulation(n, k, target);
        return ans;
    }
};