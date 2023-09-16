class Solution
{
public:
    int solveUsingRec(vector<int> &prices, int i, int buy, int &fee)
    {
        // bc
        if (i >= prices.size())
        {
            return 0;
        }

        int profit = 0;
        // when buying is allowed
        if (buy)
        {
            int buyingProfit = -prices[i] + solveUsingRec(prices, i + 1, 0, fee); // 0 because it is bought
            int skipProfit = 0 + solveUsingRec(prices, i + 1, 1, fee);            // 1 becasue it is not bought
            profit = max(buyingProfit, skipProfit);
        }
        else
        {
            int sellingProfit = prices[i] + solveUsingRec(prices, i + 1, 1, fee) - fee; // 1 because it is sold and buying is available //subtracting fee here because this is where a transaction gets complete
            int skipProfit = 0 + solveUsingRec(prices, i + 1, 0, fee);                  // 0 becasue it is not sold and buying is not available
            profit = max(sellingProfit, skipProfit);
        }
        return profit;
    }

    int solveUsingMemo(vector<int> &prices, int i, int buy, vector<vector<int>> &dp, int &fee)
    {
        // bc
        if (i >= prices.size())
        {
            return 0;
        }

        if (dp[i][buy] != -1)
        {
            return dp[i][buy];
        }

        int profit = 0;
        // when buying is allowed
        if (buy)
        {
            int buyingProfit = -prices[i] + solveUsingMemo(prices, i + 1, 0, dp, fee); // 0 because it is bought
            int skipProfit = 0 + solveUsingMemo(prices, i + 1, 1, dp, fee);            // 1 becasue it is not bought
            profit = max(buyingProfit, skipProfit);
        }
        else
        {
            int sellingProfit = prices[i] + solveUsingMemo(prices, i + 1, 1, dp, fee) - fee; // 1 because it is sold and buying is available
            int skipProfit = 0 + solveUsingMemo(prices, i + 1, 0, dp, fee);                  // 0 becasue it is not sold and buying is not available
            profit = max(sellingProfit, skipProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }

    int solveUsingTabular(vector<int> &prices, vector<vector<int>> &dp, int &fee)
    {
        int n = prices.size() - 1;
        for (int i = n; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                // when buying is allowed
                if (buy)
                {
                    int buyingProfit = -prices[i] + dp[i + 1][0]; // 0 because it is bought
                    int skipProfit = 0 + dp[i + 1][1];            // 1 becasue it is not bought
                    profit = max(buyingProfit, skipProfit);
                }
                else
                {
                    int sellingProfit = prices[i] + dp[i + 1][1] - fee; // 1 because it is sold and buying is available
                    int skipProfit = 0 + dp[i + 1][0];                  // 0 becasue it is not sold and buying is not available
                    profit = max(sellingProfit, skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        // return solveUsingMemo(prices,0,1,dp,fee);
        return solveUsingTabular(prices, dp, fee);
    }
};