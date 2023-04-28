vector<int> nextSmallerElement(vector<int> &input)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(input.size());
    int n = input.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = input[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}