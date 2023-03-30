class Solution
{
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperLeftCheck;
    unordered_map<int, bool> bottonLeftCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans)
    {
        vector<string> temp;

        for (int i = 0; i < n; i++)
        {
            string output = "";
            for (int j = 0; j < n; j++)
            {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>> &board, int n)
    {

        if (rowCheck[row] == true)
        {
            return false;
        }
        if (upperLeftCheck[n - 1 + row - col])
        {
            return false;
        }
        if (bottonLeftCheck[row + col])
        {
            return false;
        }

        // int i=row;
        // int j=col;

        // //check row
        // while(j>=0){
        //   if(board[i][j]=='Q'){
        //     return false;
        //   }
        //   j--;
        // }

        // //check upper left diagonal
        // i=row;
        // j=col;
        // while(i>=0 && j>=0){
        //   if(board[i][j]=='Q'){
        //     return false;
        //   }
        //   i--;
        //   j--;
        // }

        // //check bottom left diagonal
        // i=row;
        // j=col;
        // while(i<n && j>=0){
        //   if(board[i][j]=='Q'){
        //     return false;
        //   }
        //   i++;
        //   j--;
        // }

        return true;
    }

    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans)
    {
        // base case
        if (col >= n)
        {
            storeSolution(board, n, ans);
            return;
        }

        // 1 case solve kardo baki recursion sambhal lega

        for (int row = 0; row < n; row += 1)
        {
            if (isSafe(row, col, board, n))
            {
                // rakh do
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftCheck[n - 1 + row - col] = true;
                bottonLeftCheck[row + col] = true;
                // recursive call
                solve(board, col + 1, n, ans);
                // backtracking
                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftCheck[n - 1 + row - col] = false;
                bottonLeftCheck[row + col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int col = 0;
        solve(board, col, n, ans);
        return ans;
    }
};