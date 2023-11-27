class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>>adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int dp[5001][10];
    // int sol(int n, int cell) {
    //     if (n == 0)return 1;
    //     if (dp[n][cell] != -1)return dp[n][cell];
    //     int ans = 0;
    //     for (int&nextCell : adj[cell])
    //         ans = (ans + sol(n - 1, nextCell)) % M;

    //     return dp[n][cell] = ans;
    // }
    // int knightDialer(int n) {
    //     int result = 0;
    //     memset(dp, -1, sizeof(dp));
    //     for (int i = 0; i <=9; ++i) {
    //         result = (result + sol(n - 1, i)) % M;
    //     }
    //     return result;
    // }

    int knightDialer(int n) {
        int result = 0;

        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= 9; ++i)
            dp[0][i] = 1;  //base case

        for (int len = 1; len <= n - 1; ++len) {
            for (int cell = 0; cell <= 9; ++cell) {
                int ans = 0;
                for (int&nextCell : adj[cell]) {
                    ans = (ans + dp[len - 1][ nextCell]) % M;
                }
                dp[len][cell] = ans;
            }


        }
        for (int i = 0; i <= 9; ++i) {
            result = (result + dp[n - 1][i]) % M;
        }

        return result;
    }
};