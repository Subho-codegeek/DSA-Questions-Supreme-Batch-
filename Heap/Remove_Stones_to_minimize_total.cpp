class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;

        for (int i = 0; i < piles.size(); i++)
        {
            pq.push(piles[i]);
        }
        while (k != 0)
        {
            int data = pq.top();
            pq.pop();
            data = data - floor(data / 2);
            pq.push(data);
            k--;
        }

        int sum = 0;
        while (!pq.empty())
        {
            sum = sum + pq.top();
            pq.pop();
        }
        return sum;
    }
};