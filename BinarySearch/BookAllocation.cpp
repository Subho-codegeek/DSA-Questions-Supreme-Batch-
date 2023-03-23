class Solution
{
public:
    bool possibleSolution(int A[], int N, int M, int sol)
    {

        int pageSum = 0;
        int c = 1;

        for (int i = 0; i < N; i++)
        {
            if (A[i] > sol)
            {
                return false;
            }
            if (pageSum + A[i] > sol)
            {
                c++;
                pageSum = A[i];
                if (c > M)
                {
                    return false;
                }
            }
            else
            {
                pageSum += A[i];
            }
        }
        return true;
    }
    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        // code here
        if (M > N)
            return -1;

        int start = 0;
        int end = accumulate(A, A + N, 0);
        int ans = -1;

        int mid = start + (end - start) / 2;

        while (start <= end)
        {
            if (possibleSolution(A, N, M, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
};