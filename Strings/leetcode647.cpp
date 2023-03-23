class Solution
{
public:
    int expandAroundIndex(string s, int i, int j)
    {
        int count = 0;

        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            count += 1;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s)
    {

        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {

            // odd
            int oddKaAns = expandAroundIndex(s, i, i); // i,j is same
            count += oddKaAns;

            // even
            int evenKaAns = expandAroundIndex(s, i, i + 1); // j is after i
            count += evenKaAns;
        }

        return count;
    }
};