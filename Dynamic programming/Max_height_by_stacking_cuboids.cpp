// lis ka concept

class Solution
{
public:
    bool check(vector<int> &a, vector<int> &b)
    {
        if (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
            return true;
        else
            return false;
    }
    int solveUsingTab(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                // include
                if (prev == -1 || check(nums[curr], nums[prev]))
                    include = nums[curr][2] + dp[curr + 1][curr + 1]; // curr+1 because prev -1 ka ans 0 index pe hei, prev 0 ka ans 1 index pe hei and aise har ek ka ans ek index aage ayega
                                                                      // curr because current element ko he include karneka bat ho raha hei
                // exclude
                int exclude = 0 + dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][-1 + 1];
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        // sort every array
        for (auto &a : cuboids)
        {
            sort(a.begin(), a.end());
        }

        // sort the 2D array
        sort(cuboids.begin(), cuboids.end());

        int ans = solveUsingTab(cuboids);
        return ans;
    }
};