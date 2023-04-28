class Solution
{
public:
    vector<int> prevSmallerElement(vector<int> &input)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(input.size());
        int n = input.size();
        for (int i = 0; i < n; i++)
        {
            int curr = input[i];
            while (st.top() != -1 && input[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerElement(vector<int> &input)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(input.size());
        int n = input.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = input[i];
            while (st.top() != -1 && input[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> prev = prevSmallerElement(heights);
        vector<int> next = nextSmallerElement(heights);

        int size = heights.size();
        int maxArea = INT_MIN;

        for (int i = 0; i < heights.size(); i++)
        {

            int length = heights[i];
            if (next[i] == -1)
            {
                next[i] = size;
            }

            int width = next[i] - prev[i] - 1;

            int area = length * width;

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};