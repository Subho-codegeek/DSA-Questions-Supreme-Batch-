class Solution
{
public:
    int solve(vector<int> &nums, int i)
    {
        // base case
        //  if(i>=nums.size()){
        //      maxi=max(maxi,sum);
        //      return;
        //  }

        // //include
        // int x=sum+nums[i];
        // solve(nums,i+2,maxi,x);
        // //exclude
        // solve(nums,i+1,maxi,sum);
        if (i >= nums.size())
        {
            return 0;
        }
        int robAmt1 = nums[i] + solve(nums, i + 2);
        int robAmt2 = 0 + solve(nums, i + 1);

        return max(robAmt1, robAmt2);
    }
    int rob(vector<int> &nums)
    {
        int i = 0;
        return solve(nums, i);
    }
};