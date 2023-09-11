#include <iostream>
#include <map>
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

Node *buildTree()
{
    int data;
    cout << "Enter data:";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    cout << "Enter data to the left of " << data << endl;
    root->left = buildTree();
    cout << "Enter data to the right of " << data << endl;
    root->right = buildTree();

    return root;
}

void printTopView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // creating map for storig hd->topNode->data
    map<int, int> topNode;

    // creating queue for level order traversal approach
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        if (topNode.find(hd) == topNode.end())
        { // this line means that mapping ke
          // andar hd ka koi data nahi mila
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // answer
    for (auto i : topNode)
    {
        cout << i.first << " -> " << i.second << endl;
    }
}

void printBottomView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // creating map for storig hd->topNode->data
    map<int, int> topNode;

    // creating queue for level order traversal approach
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // jitna deep tak hd(height difference ja sakta hei utna jao bina kisi consition ka)
        topNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // answer
    for (auto i : topNode)
    {
        cout << i.first << " -> " << i.second << endl;
    }
}

void printLeftView(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size()) // at every level if the size of ans array is equal to the level then we will push the element
    {
        ans.push_back(root->data);
    }

    printLeftView(root->left, ans, level + 1);
    printLeftView(root->right, ans, level + 1);
}

void printRightView(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size()) // at every level if the size of ans array is equal to the level then we will push the element
    {
        ans.push_back(root->data);
    }

    // we will make the right call first in case of right view
    printRightView(root->right, ans, level + 1);
    printRightView(root->left, ans, level + 1);
}

void printLeftBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // if its a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    cout << root->data << " ";

    if (root->left)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // if its a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // if its a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }

    cout << root->data << " ";
}

void BoundaryTraversal(Node *root)
{
    // BC
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    // A - Left Ndoes
    printLeftBoundary(root->left);
    // B - Leaf Nodes
    printLeafBoundary(root);
    // C - Right Nodes
    printRightBoundary(root->right);
}

int main()
{
    Node *root = buildTree();
    // printBottomView(root);
    //  vector<int> ans;
    //  int level=0;
    //  printLeftView(root,ans,level);
    //  for(auto i:ans){
    //    cout<<i<<" "<<endl;
    //  }
    BoundaryTraversal(root);
}