Node *sortedLinkedListIntoBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    // left ka call
    Node *leftSubTree = sortedLinkedListIntoBST(head, n - 1 - n / 2);

    // update head
    Node *root = head;
    root->left = leftSubTree;

    // head ko aage badhao
    head = head->right;

    // right ko call karke jor do
    root->right = sortedLinkedListIntoBST(head, n / 2);
    return root;
}