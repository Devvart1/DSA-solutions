
#include <bits/stdc++.h>
using namespace std;

int sol(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int l = 0;
    int r = 0;

    if ((i - 1) >= 0)
        l = sol(i - 1, j, dp);
    if (j - 1 >= 0)
        r = sol(i, j - 1, dp);

    return dp[i][j] = l + r;
}

int uniquePaths(int m, int n)
{
    // int dp[m][n];
    // dp[0][0] = 1;
    vector<int> x(n, 0);

    for (int i = 0; i < m; ++i)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; ++j)
        {
           

            if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
 int l = 0;
 int r=0;
                if (j >0)
                    l = temp[j - 1];
                if(i>0)
                    r=x[j];

                temp[j] = l+r;
            }
            // cout<<x[]<<endl;
        }
        x = temp;
    }
    return x[n - 1];
}

int main()
{

    cout << uniquePaths(3, 7);
}