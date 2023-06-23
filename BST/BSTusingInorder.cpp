Node *BSTusingInorder(int inorder[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);

    root->left = BSTusingInorder(inorder, s, mid - 1);
    root->right = BSTusingInorder(inorder, mid + 1, e);

    return root;
}