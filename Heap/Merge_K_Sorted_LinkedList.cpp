class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;
        int k = lists.size();
        if (k == 0)
        {
            return NULL;
        }
        // first element of every linkedlist ko insert karo
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;

        while (!minHeap.empty())
        {
            ListNode *temp = minHeap.top();
            minHeap.pop();

            if (head == NULL)
            {
                // temp is the fist node
                head = temp;
                tail = temp;
                if (tail->next != NULL)
                {
                    minHeap.push(tail->next);
                }
            }
            else
            {
                tail->next = temp;
                tail = temp;
                if (tail->next != NULL)
                {
                    minHeap.push(tail->next);
                }
            }
        }
        return head;
    }
};