class Solution
{
public:
    // dp topDown approach
    int topDown(int n, vector<int> &dp)
    {
        if (n == 1 || n == 0)
        {
            return n;
        }
        // step 3: check if answer exists
        if (dp[n] != -1)
        {
            return dp[n];
        }
        // step 2: store ans
        dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);
        return dp[n];
    }

    // dp bottomDown approach
    int bottomDown(int n)
    {
        // step 1: create array
        vector<int> dp(n + 1, -1);

        // step 2: store the base case value
        dp[0] = 0;
        if (n == 0)
        {
            return dp[0];
        }
        dp[1] = 1;

        // step 3: for loop ke andar ans store karo
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // space optimisation
    int spaceOpt(int n)
    {
        int prev2 = 0;
        int prev1 = 1;
        if (n == 0)
        {
            return prev2;
        }
        if (n == 1)
        {
            return prev1;
        }
        int curr = -1;
        for (int i = 2; i <= n; i++)
        {
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int fib(int n)
    {
        // if(n==0||n==1){
        //     return n;
        // }
        // int ans = fib(n-1)+fib(n-2);
        // return ans;

        // step1: create dp array
        vector<int> dp(n + 1, -1);
        int ans = spaceOpt(n);
        return ans;
    }
};