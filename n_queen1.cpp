
class Solution {
public:

    bool possible(int row, int colm, int n, vector<string> &temp) {



        int r = row;
        int c = colm;

        while (c >= 0) {
            if (temp[row][c] == 'Q')return false;
            c--;
        }
        r = row;
        c = colm;

        while (r<n and c >= 0) {
            if (temp[r][c] == 'Q')return false;
            r++;
            c--;
        }
        r = row;
        c = colm;
        while (r >= 0 and c >= 0) {
            if (temp[r][c] == 'Q')return false;
            r--;
            c--;
        }
        return true;

    }
    void sol( vector<vector<string>> &ans, vector<string> &temp, int colm, int n, vector<int> &leftRow, vector<int> &upperDia, vector<int> &lowerDia) {
        if (colm == n) {ans.push_back(temp); return;}

        for (int row = 0; row < n; ++row) {

            if (leftRow[row] == 0 and upperDia[n - 1 + colm - row] == 0 and lowerDia[row + colm] == 0)  {

                temp[row][colm] = 'Q';
                leftRow[row] = 1;
                upperDia[n - 1 + colm - row] = 1;
                lowerDia[row + colm] = 1;
                sol(ans, temp, colm + 1, n, leftRow, upperDia, lowerDia);
                temp[row][colm] = '.';
                leftRow[row] = 0;
                upperDia[n - 1 + colm - row] = 0;
                lowerDia[row + colm] = 0;

            }

        }




    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> temp(n);
        vector<int> leftRow(n, 0), upperDia(2 * n - 1, 0), lowerDia(2 * n - 1, 0);

        set<int> col;
        string s(n, '.');
        for (int i = 0; i < n; ++i) {
            temp[i] = s;
        }
        sol(ans, temp, 0, n, leftRow, upperDia, lowerDia);
        return ans;
    }
};