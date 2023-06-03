// similar to the preorder and inorder problem.

class Solution
{
public:
    int findPosition(vector<int> inorder, int size, int element)
    {
        for (int i = 0; i < size; i++)
        {
            if (inorder[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode *buildTreeFromPostorderInorder(vector<int> &inorder, vector<int> &postorder, int size, int &postIndex, int inorderStart, int inorderEnd)
    {

        if (postIndex < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = postorder[postIndex--];
        TreeNode *root = new TreeNode(element);
        int pos = findPosition(inorder, size, element);

        // solving for right
        root->right = buildTreeFromPostorderInorder(inorder, postorder, size, postIndex, pos + 1, inorderEnd);
        // solving for left
        root->left = buildTreeFromPostorderInorder(inorder, postorder, size, postIndex, inorderStart, pos - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int size = inorder.size();
        int postIndex = size - 1;
        int inorderStart = 0;
        int inorderEnd = size - 1;
        TreeNode *x = buildTreeFromPostorderInorder(inorder, postorder, size, postIndex, inorderStart, inorderEnd);
        return x;
    }
};