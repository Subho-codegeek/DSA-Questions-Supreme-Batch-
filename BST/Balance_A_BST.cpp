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
    TreeNode *solve(vector<int> inorder, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }

        int mid = (s + e) / 2;
        int element = inorder[mid];
        TreeNode *root = new TreeNode(element);

        root->left = solve(inorder, s, mid - 1);
        root->right = solve(inorder, mid + 1, e);

        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorder;
        convertInorder(root, inorder);
        int s = 0;
        int e = inorder.size() - 1;
        TreeNode *x = solve(inorder, s, e);
        return x;
    }
};