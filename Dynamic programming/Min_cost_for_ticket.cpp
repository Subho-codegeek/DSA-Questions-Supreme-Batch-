class Solution
{
public:
    int solveUsingRec(vector<int> &days, vector<int> &costs, int i)
    {
        // base case
        if (i >= days.size())
            return 0;

        // 1 day cost
        int cost1 = costs[0] + solveUsingRec(days, costs, i + 1);

        // 7 days cost
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (days[j] <= passEndDay && j < days.size())
        {
            j++;
        }
        int cost7 = costs[1] + solveUsingRec(days, costs, j);

        // 30 days cost
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (days[j] <= passEndDay && j < days.size())
        {
            j++;
        }
        int cost30 = costs[2] + solveUsingRec(days, costs, j);

        return min(cost1, min(cost7, cost30));
    }

    int solveUsingMemo(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
    {
        // base case
        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
        {
            return dp[i];
        }

        // 1 day cost
        int cost1 = costs[0] + solveUsingMemo(days, costs, i + 1, dp);

        // 7 days cost
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost7 = costs[1] + solveUsingMemo(days, costs, j, dp);

        // 30 days cost
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost30 = costs[2] + solveUsingMemo(days, costs, j, dp);

        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }

    int solveUsingTabular(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
    {
        dp[days.size()] = 0;

        for (int i = days.size() - 1; i >= 0; i--)
        {
            // 1 day cost
            int cost1 = costs[0] + dp[i + 1];

            // 7 days cost
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while (j < days.size() && days[j] <= passEndDay)
            {
                j++;
            }
            int cost7 = costs[1] + dp[j];

            // 30 days cost
            passEndDay = days[i] + 30 - 1;
            j = i;
            while (j < days.size() && days[j] <= passEndDay)
            {
                j++;
            }
            int cost30 = costs[2] + dp[j];

            dp[i] = min(cost1, min(cost7, cost30));
        }
        return dp[0];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size() + 1, -1);
        int ans = solveUsingTabular(days, costs, 0, dp);
        return ans;
    }
};