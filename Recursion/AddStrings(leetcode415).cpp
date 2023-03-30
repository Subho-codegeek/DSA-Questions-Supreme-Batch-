class Solution
{
public:
    void solve(string &num1, int p1, string &num2, int p2, int carry, string &ans)
    {
        // Base case
        if (p1 < 0 && p2 < 0)
        {
            if (carry != 0)
            {
                ans.push_back(carry + '0');
            }
            return;
        }

        // 1 case
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int cSum = n1 + n2 + carry;
        int digit = cSum % 10;
        carry = cSum / 10;
        ans.push_back(digit + '0');

        // Recursion sambhal lega
        solve(num1, p1 - 1, num2, p2 - 1, carry, ans);
    }
    string addStrings(string num1, string num2)
    {
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        string ans = "";
        int carry = 0;
        solve(num1, p1, num2, p2, carry, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};