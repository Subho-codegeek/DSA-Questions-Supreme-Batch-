class Solution
{
public:
    bool checkWord(string word, vector<string> wordDict)
    {
        for (auto i : wordDict)
        {
            if (word == i)
            {
                return true;
            }
        }
        return false;
    }
    bool solve(string s, vector<string> &wordDict, int start)
    {
        if (start >= s.size())
            return true;

        // one case, make a string
        string word = "";
        bool flag = false;
        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if (checkWord(word, wordDict))
            {
                flag = flag || solve(s, wordDict, i + 1);
            }
        }
        return flag;
    }

    bool solveUsingMemo(string s, vector<string> &wordDict, int start, vector<int> &dp)
    {
        if (start >= s.size())
            return true;
        if (dp[start] != -1)
        {
            return dp[start];
        }
        // one case, make a string
        string word = "";
        bool flag = false;
        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if (checkWord(word, wordDict))
            {
                flag = flag || solveUsingMemo(s, wordDict, i + 1, dp);
            }
        }
        dp[start] = flag;
        return dp[start];
    }

    bool solveUsingTabular(string s, vector<string> &wordDict, vector<int> &dp)
    {
        for (int start = s.size() - 1; start >= 0; start--)
        {
            // one case, make a string
            string word = "";
            bool flag = false;
            for (int i = start; i < s.size(); i++)
            {
                word += s[i];
                if (checkWord(word, wordDict))
                {
                    flag = flag || dp[i + 1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, 1);
        // return solve(s,wordDict,0);
        // return solveUsingMemo(s,wordDict,0,dp);
        return solveUsingTabular(s, wordDict, dp);
    }
};