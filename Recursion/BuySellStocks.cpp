class Solution
{
public:
    void solve(vector<int> &prices, int &minPrice, int &maxProfit, int index)
    {
        // base case
        if (index >= prices.size())
        {
            return;
        }
        // 1 case
        if (prices[index] < minPrice)
        {
            minPrice = prices[index];
        }
        int todayProfit = prices[index] - minPrice;
        if (todayProfit > maxProfit)
        {
            maxProfit = todayProfit;
        }
        // recursion sambhal lega
        solve(prices, minPrice, maxProfit, index + 1);
    }
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        solve(prices, minPrice, maxProfit, 0);
        return maxProfit;
    }
};