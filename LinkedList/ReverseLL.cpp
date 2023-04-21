#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverse(Node *&prev, Node *&curr)
{
    if (curr == NULL)
    {
        return prev;
    }

    Node *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;

    reverse(prev, curr);
}