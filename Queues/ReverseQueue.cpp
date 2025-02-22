#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // step 1: put all elements of q into s
    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        s.push(element);
    }

    // step2: put all element from stackinto q
    while (!s.empty())
    {
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void reverseQueueRecursion(queue<int> &q)
{
    // Base case
    if (q.empty())
        return;

    // step A
    int temp = q.front();
    q.pop();

    // step B
    reverseQueueRecursion(q);

    // step C;
    q.push(temp);
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    reverseQueueRecursion(q);

    cout << "printing Queue after reversing recursively" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}