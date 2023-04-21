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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int length(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *reverseKnodes(Node *&head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int len = length(head);
    if (k > len)
    {
        return head;
    }

    int count = 0;
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;

    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL)
    {
        head->next = reverseKnodes(forward, k);
    }

    return prev;
}