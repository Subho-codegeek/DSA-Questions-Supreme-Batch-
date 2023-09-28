class Solution
{
public:
    void countZerosOnesFunc(vector<string> &strs, vector<pair<int, int>> &countZerosOnes)
    {
        for (auto str : strs)
        {
            int zeros = 0;
            int ones = 0;
            for (auto ch : str)
            {
                if (ch == '0')
                    ++zeros;
                else
                    ++ones;
            }
            countZerosOnes.push_back({zeros, ones});
        }
    }

    int solveUsingRec(vector<pair<int, int>> &countZerosOnes, int i, int m, int n)
    {
        // bc
        if (i >= countZerosOnes.size())
            return 0;

        int countZeros = countZerosOnes[i].first;
        int countOnes = countZerosOnes[i].second;

        int include = 0, exclude = 0;

        if (m - countZeros >= 0 && n - countOnes >= 0)
        {
            include = 1 + solveUsingRec(countZerosOnes, i + 1, m - countZeros, n - countOnes);
        }
        exclude = 0 + solveUsingRec(countZerosOnes, i + 1, m, n);
        return max(include, exclude);
    }

    int solveUsingMemo(vector<pair<int, int>> &countZerosOnes, int i, int m, int n, vector<vector<vector<int>>> &dp)
    {
        // bc
        if (i >= countZerosOnes.size())
            return 0;
        if (dp[i][m][n] != -1)
        {
            return dp[i][m][n];
        }

        int countZeros = countZerosOnes[i].first;
        int countOnes = countZerosOnes[i].second;

        int include = 0, exclude = 0;

        if (m - countZeros >= 0 && n - countOnes >= 0)
        {
            include = 1 + solveUsingMemo(countZerosOnes, i + 1, m - countZeros, n - countOnes, dp);
        }
        exclude = 0 + solveUsingMemo(countZerosOnes, i + 1, m, n, dp);

        dp[i][m][n] = max(include, exclude);
        return dp[i][m][n];
    }

    int solveUsingTabular(vector<pair<int, int>> &countZerosOnes, int m, int n)
    {
        vector<vector<vector<int>>> dp(countZerosOnes.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = countZerosOnes.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {

                    int countZeros = countZerosOnes[i].first;
                    int countOnes = countZerosOnes[i].second;

                    int include = 0, exclude = 0;

                    if (j - countZeros >= 0 && k - countOnes >= 0)
                    {
                        include = 1 + dp[i + 1][j - countZeros][k - countOnes]; // solveUsingMemo(countZerosOnes,i+1,m-countZeros, n-countOnes,dp);
                    }
                    exclude = 0 + dp[i + 1][j][k]; // solveUsingMemo(countZerosOnes,i+1,m,n,dp);

                    dp[i][j][k] = max(include, exclude);
                }
            }
        }
        return dp[0][m][n];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> countZerosOnes; // vector storing count of zeroes and ones of each string element of the strs array.
        countZerosOnesFunc(strs, countZerosOnes);
        // vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        // int i=0;
        // return solveUsingRec(countZerosOnes,i,m,n);
        // return solveUsingMemo(countZerosOnes,i,m,n,dp);
        return solveUsingTabular(countZerosOnes, m, n);
    }
};