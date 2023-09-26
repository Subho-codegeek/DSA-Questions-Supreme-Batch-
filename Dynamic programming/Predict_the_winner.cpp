class Solution
{
public:
    int solve(int start, int end, vector<int> &nums)
    {
        // bc
        if (start == end)
            return nums[start];

        // differnce = p1-p2
        int startDiff = nums[start] - solve(start + 1, end, nums);
        int endDiff = nums[end] - solve(start, end - 1, nums);
        return max(startDiff, endDiff);
    }
    int solveUsingMemo(int start, int end, vector<int> &nums, vector<vector<int>> &dp)
    {
        // bc
        if (start == end)
            return nums[start];
        if (dp[start][end] != -1)
            return dp[start][end];

        // differnce = p1-p2
        int startDiff = nums[start] - solveUsingMemo(start + 1, end, nums, dp);
        int endDiff = nums[end] - solveUsingMemo(start, end - 1, nums, dp);
        dp[start][end] = max(startDiff, endDiff);
        return dp[start][end];
    }
    // int solveUsingTabular(vector<int>& nums,vector<vector<int>> &dp){
    //     int n = nums.size();
    //     for(int start=n-1; start>=0; start--){
    //         for(int end=0; end<=n-1; end++){
    //             int startDiff = nums[start] - dp[start+1][end];
    //             int endDiff = nums[end] - dp[start][end-1];
    //             dp[start][end] = max(startDiff,endDiff);
    //         }
    //     }
    //     return dp[0][n-1];
    // }
    bool predictTheWinner(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        // return solveUsingTabular(nums,dp)>=0;
        return solveUsingMemo(0, nums.size() - 1, nums, dp) >= 0;
    }
};