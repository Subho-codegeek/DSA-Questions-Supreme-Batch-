class Node
{
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {

        priority_queue<Node *, vector<Node *>, compare> minHeap;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        int k = nums.size();

        for (int i = 0; i < k; i++)
        {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new Node(element, i, 0));
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while (!minHeap.empty())
        {
            Node *top = minHeap.top();
            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();

            // mini updating
            mini = topElement;

            // check for answer
            int currRange = maxi - mini;
            int ansRange = ansEnd - ansStart;
            if (currRange < ansRange)
            {
                ansStart = mini;
                ansEnd = maxi;
            }

            if (topCol + 1 < nums[topRow].size())
            {
                maxi = max(maxi, nums[topRow][topCol + 1]);
                minHeap.push(new Node(nums[topRow][topCol + 1], topRow, topCol + 1));
            }
            else
            {
                break;
            }
        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};