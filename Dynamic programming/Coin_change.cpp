class Solution
{
public:
    // recursive approach
    int recursiveSol(vector<int> &coins, int amount)
    {
        // base case
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return INT_MAX;
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = recursiveSol(coins, amount - coins[i]);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }
        return mini;
    }

    // bottomup dp appraoch
    int memo(vector<int> &coins, int amount, vector<int> &dp)
    {
        // base case
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return INT_MAX;
        }
        // step 3: check karo base case ke badh
        if (dp[amount] != -1)
        {
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = memo(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }
        // step 2: ans ko dp se replace karo or store karo
        dp[amount] = mini;
        return dp[amount];
    }

    // topdown dp appraoch
    int topdown(vector<int> &coins, int amount)
    {
        // step 1
        vector<int> dp(amount + 1, INT_MAX); // INT_MAX because we need to store minimum no. of coins.

        // step 2
        dp[0] = 0; // base case. 0 return karna hei jab amount 0 ho jaye

        // step 3
        for (int target = 1; target <= amount; target++)
        {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
            {
                if (target - coins[i] >= 0)
                {
                    int ans = dp[target - coins[i]];
                    if (ans != INT_MAX)
                    {
                        mini = min(mini, 1 + ans);
                    }
                }
            }
            dp[target] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        // for recursive part
        //  int ans = recursiveSol(coins,amount);
        //  if(ans==INT_MAX){
        //      return -1;
        //  }
        //  return ans;

        // for bottomup dp;
        // step1
        // vector<int> dp(amount+1,-1); //INT_MAX because we need to store minimum no. of coins.
        //  int ans = memo(coins,amount,dp);
        //  if(ans==INT_MAX){
        //      return -1;
        //  }
        //  return ans;

        // for topdown dp
        int ans = topdown(coins, amount);
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};