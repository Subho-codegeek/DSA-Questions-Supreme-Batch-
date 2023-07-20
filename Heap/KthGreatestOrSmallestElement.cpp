#include <iostream>
#include <queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k)
{
    // create max heap
    priority_queue<int> pq;
    // insert initial k elements
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // for remaining elements push only if they are smaller than top
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}

int getKthGreatestElement(int arr[], int n, int k)
{
    // create max heap
    priority_queue<int, vector<int>, greater<int>> pq;
    // insert initial k elements
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // for remaining elements push only if they are greater than top
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[] = {10, 5, 20, 4, 15, 25};
    int n = 6;
    int k = 5;
    int ans = getKthGreatestElement(arr, n, k);
    cout << "Ans is: " << ans << endl;
    return 0;
}