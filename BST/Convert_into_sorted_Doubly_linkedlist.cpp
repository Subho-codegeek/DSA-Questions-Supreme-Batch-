void covertIntoSortedDll(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }

    // right subtree call
    covertIntoSortedDll(root->right, head);

    // root attach
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }

    // update head
    head = root;

    // left subtree call
    covertIntoSortedDll(root->left, head);
}