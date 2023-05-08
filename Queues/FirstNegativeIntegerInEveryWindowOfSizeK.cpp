// Sliding window concept
#include <iostream>
#include <queue>
using namespace std;

void solve(int arr[], int n, int k)
{
    queue<int> q;
    // A: Process first window of size k
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }
    // B: Remaining window ko process karo
    for (int i = k; i < n; i++)
    {
        // answer dedo purani window ka
        if (q.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << arr[q.front()] << " ";
        }

        // out of window elemet ko remove kardo
        while ((!q.empty()) && (i - q.front() >= k))
        {
            q.pop();
        }

        // check current element for insertion
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }
    // answer print karo last window ka
    if (q.empty())
    {
        cout << 0 << " ";
    }
    else
    {
        cout << arr[q.front()] << " ";
    }
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;

    int k = 3;

    solve(arr, size, k);

    return 0;
}