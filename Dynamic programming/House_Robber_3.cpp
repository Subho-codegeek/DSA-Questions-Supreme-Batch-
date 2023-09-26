/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;

        int rob = 0, dontRob = 0;

        // rob this house
        rob += root->val;
        if (root->left)
        {
            rob += solve(root->left->left) + solve(root->left->right);
        }
        if (root->right)
        {
            rob += solve(root->right->left) + solve(root->right->right);
        }

        // do not rob this house
        dontRob += solve(root->left) + solve(root->right);

        return max(rob, dontRob);
    }

    int solveUsingMemo(TreeNode *root, unordered_map<TreeNode *, int> &dp)
    {
        if (!root)
            return 0;
        if (dp.find(root) != dp.end())
            return dp[root];

        int rob = 0, dontRob = 0;

        // rob this house
        rob += root->val;
        if (root->left)
        {
            rob += solveUsingMemo(root->left->left, dp) + solveUsingMemo(root->left->right, dp);
        }
        if (root->right)
        {
            rob += solveUsingMemo(root->right->left, dp) + solveUsingMemo(root->right->right, dp);
        }

        // do not rob this house
        dontRob += solveUsingMemo(root->left, dp) + solveUsingMemo(root->right, dp);

        dp[root] = max(rob, dontRob);
        return dp[root];
    }
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> dp;
        // return solve(root);
        return solveUsingMemo(root, dp);
    }
};