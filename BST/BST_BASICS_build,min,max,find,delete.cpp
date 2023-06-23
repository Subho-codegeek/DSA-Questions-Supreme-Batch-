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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // first node we have to create
        root = new Node(data);
        return root;
    }

    // not the first node;
    if (root->data > data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        // B
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
            // C
            cout << temp->data << " ";
            // D
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

bool findNode(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    if (target > root->data)
    {
        rightAns = findNode(root->right, target);
    }
    else
    {
        leftAns = findNode(root->left, target);
    }
    return leftAns || rightAns;
}

int minVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

Node *deleteNodeInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *child = root->right;
            return child;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            return child;
        }
        else
        {
            int inorderPre = maxVal(root->left);
            root->data = inorderPre;
            root->left = deleteNodeInBST(root->left, inorderPre);
            return root;
        }
    }
    else if (target > root->data)
    {
        root->right = deleteNodeInBST(root->right, target);
    }
    else if (target < root->data)
    {
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data for Node " << endl;
    takeInput(root);
    cout << "Printing the tree" << endl;
    levelOrderTraversal(root);
    cout << endl;

    //  bool ans  = findNode(root,12);
    // cout << "present or not : " << ans << endl;

    cout << endl
         << " Minimum value: " << minVal(root) << endl;
    cout << endl
         << "Maximum value: " << maxVal(root) << endl;
    return 0;
}