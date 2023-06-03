#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = left = NULL;
        this->right = right = NULL;
    }
};

int findPosition(int inorder[], int size, int element)
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

Node *buildTreeFromPreorderInorder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{

    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = preorder[preIndex++];
    Node *root = new Node(element);
    int pos = findPosition(inorder, size, element);

    // solving for left
    root->left = buildTreeFromPreorderInorder(inorder, preorder, size, preIndex, inorderStart, pos - 1);
    // solving for right
    root->right = buildTreeFromPreorderInorder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);

    return root;
}

void levelOrderTraversal(Node *root)
{

    queue<Node *> q;

    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    int preorder[] = {5, 1, 3, 4, 2};
    int inorder[] = {3, 1, 4, 5, 2};
    int size = 5;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    Node *root = buildTreeFromPreorderInorder(preorder, inorder, size, preIndex, inorderStart, inorderEnd);
    levelOrderTraversal(root);
    return 0;
}