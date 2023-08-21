#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    int ans = (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k)) * (k - 1);

    return ans;
}

int solveUsingMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (solveUsingMemo(n - 2, k, dp) + solveUsingMemo(n - 1, k, dp)) * (k - 1);

    return dp[n];
}

int solveUsingTabular(int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = (k + k * (k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
    }
    return dp[n];
}

int solveUsingSpaceOptimised(int n, int k)
{
    int prev2 = k;
    int prev1 = (k + k * (k - 1));

    for (int i = 3; i <= n; i++)
    {
        int curr = (prev2 + prev1) * (k - 1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n = 4;
    int k = 3;
    vector<int> dp(n + 1, -1);
    int ans = solveUsingSpaceOptimised(n, k);
    cout << ans << endl;
    return 0;
}