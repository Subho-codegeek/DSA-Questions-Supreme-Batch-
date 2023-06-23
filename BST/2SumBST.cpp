class Solution
{
public:
    void convertInorder(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }
        convertInorder(root->left, inorder);
        inorder.push_back(root->val);
        convertInorder(root->right, inorder);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        convertInorder(root, inorder);
        int s = 0;
        int e = inorder.size() - 1;
        while (s < e)
        {
            int sum = inorder[s] + inorder[e];
            if (sum == k)
            {
                return true;
            }
            if (sum > k)
            {
                e--;
            }
            if (sum < k)
            {
                s++;
            }
        }
        return false;
    }
};