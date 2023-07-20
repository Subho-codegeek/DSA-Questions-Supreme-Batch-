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
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node *, vector<Node *>, compare> minHeap;

        for (int i = 0; i < K; i++)
        {
            minHeap.push(new Node(arr[i][0], i, 0));
        }

        vector<int> ans;

        while (!minHeap.empty())
        {
            Node *top = minHeap.top();
            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;
            minHeap.pop();

            ans.push_back(topElement);

            if (topCol + 1 < K)
            {
                minHeap.push(new Node(arr[topRow][topCol + 1], topRow, topCol + 1));
            }
        }
        return ans;
    }
};