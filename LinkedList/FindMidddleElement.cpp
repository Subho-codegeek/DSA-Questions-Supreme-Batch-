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

Node *getMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty linkedlist" << endl;
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }

    Node *fast = head;
    Node *slow = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
