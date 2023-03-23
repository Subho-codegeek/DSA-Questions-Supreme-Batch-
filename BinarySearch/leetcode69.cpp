class Solution
{
public:
    int mySqrt(int x)
    {
        int s = 0;
        int e = x;
        int mid = s + (e - s) / 2;
        int ans = -1;
        int target = x;
        while (s <= e)
        {
            if (x == 0 || x == 1)
            {
                return x;
            }
            if (mid > 0 && mid == target / mid)
            {
                return mid;
            }
            else if (mid > 0 && mid > target / mid)
            {
                e = mid - 1;
            }
            else if (mid > 0 && mid < target / mid)
            {
                ans = mid;
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};