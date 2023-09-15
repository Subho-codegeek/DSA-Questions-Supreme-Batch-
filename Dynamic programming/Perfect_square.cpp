class Solution
{
public:
    int solveUsingRec(int n)
    {
        // bc
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX;
        while (i <= end)
        {
            int perfSqaure = i * i;
            int numberOfSquares = 1 + solveUsingRec(n - perfSqaure);
            ans = min(ans, numberOfSquares);
            ++i;
        }
        return ans;
    }

    int solveUsingMemo(int n, vector<int> &dp)
    {
        // bc
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (dp[n] != -1)
        {
            return dp[n];
        }

        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX;
        while (i <= end)
        {
            int perfSqaure = i * i;
            int numberOfSquares = 1 + solveUsingMemo(n - perfSqaure, dp);
            ans = min(ans, numberOfSquares);
            ++i;
        }

        dp[n] = ans;
        return dp[n];
    }

    int solveUsingTabular(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            int start = 1;
            int end = sqrt(i);
            int ans = INT_MAX;
            while (start <= end)
            {
                int perfSqaure = start * start;
                int numberOfSquares = 1 + dp[i - perfSqaure];
                ans = min(ans, numberOfSquares);
                ++start;
            }
            dp[i] = ans;
        }
        return dp[n];
    }

    int numSquares(int n)
    {
        // vector<int> dp(n+1, -1);
        int ans = solveUsingTabular(n) - 1;
        return ans;
    }
};