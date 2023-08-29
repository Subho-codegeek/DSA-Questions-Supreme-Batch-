#include <iostream>
#include <vector>
using namespace std;

int solveUsingRec(int weight[], int value[], int index, int capacity)
{
    // bc
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingRec(weight, value, index - 1, capacity - weight[index]);
    }
    int exclude = 0 + solveUsingRec(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int solveUsingMemo(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    // bc
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingMemo(weight, value, index - 1, capacity - weight[index], dp);
    }
    int exclude = 0 + solveUsingMemo(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int tabulation(int weight[], int value[], int n, int capacity)
{

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    for (int w = weight[0]; w < capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index <= n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + dp[index - 1][wt - weight[index]];
            }
            int exclude = 0 + dp[index - 1][wt];

            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int solveUsingSP(int weight[], int value[], int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w < capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index <= n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + prev[wt - weight[index]];
            }
            int exclude = 0 + prev[wt];

            curr[wt] = max(include, exclude);
        }
        // shift
        prev = curr;
    }
    return prev[capacity];
}

int solveUsingSP2(int weight[], int value[], int n, int capacity)
{

    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w < capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int index = 1; index <= n; index++)
    {
        for (int wt = capacity; wt >= 0; wt--)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + curr[wt - weight[index]];
            }
            int exclude = 0 + curr[wt];

            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    // int ans = solveUsingRec(weight,value,n-1,capacity); // n-1 is the last index of the weight

    int ans = solveUsingSP2(weight, value, n, capacity);

    cout << "ans: " << ans << endl;
}