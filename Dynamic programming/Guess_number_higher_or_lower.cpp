class Solution
{
public:
    int solveUsingRec(int left, int right)
    {
        // bc
        if (left >= right)
        {
            return 0;
        }

        int ans = INT_MAX;
        for (int i = left; i <= right; i++)
        {
            ans = min(ans, i + max(solveUsingRec(left, i - 1), solveUsingRec(i + 1, right)));
        }

        return ans;
    }

    int solveUsingMemo(int left, int right, vector<vector<int>> &dp)
    {
        // bc
        if (left >= right)
        {
            return 0;
        }
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int i = left; i <= right; i++)
        {
            ans = min(ans, i + max(solveUsingMemo(left, i - 1, dp), solveUsingMemo(i + 1, right, dp)));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }

    int solveUsingTab(int n)
    {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int left = n; left >= 1; left--)
        {
            for (int right = 1; right <= n; right++)
            {

                if (left >= right)
                {
                    continue; // ye if wala stament likhan vul jaunga mei humesha
                }

                int ans = INT_MAX;
                for (int i = left; i <= right; i++)
                {
                    ans = min(ans, i + max(dp[left][i - 1], dp[i + 1][right]));
                }
                dp[left][right] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // int ans = solveUsingRec(1,n);
        // int ans = solveUsingMemo(1,n,dp);
        int ans = solveUsingTab(n);
        return ans;
    }
};