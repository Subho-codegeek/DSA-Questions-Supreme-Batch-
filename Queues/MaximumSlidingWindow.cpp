class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        // first k boxes
        for (int i = 0; i < k; i++)
        {
            // chote element remove kardo
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // inserting index so that we can checkout of window element
            dq.push_back(i);
        }
        // storing the answer for the firt window
        ans.push_back(nums[dq.front()]);

        // checking for rest of the boxes or windows
        for (int i = k; i < nums.size(); i++)
        {
            // removing out of window element
            while (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }

            // ab firse current element ke lia chote element ko remove kardo
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // inserting index so that we can check out of window element
            dq.push_back(i);

            // current window ka answer store karna hei
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};