class Solution {
public:

	int sol(vector<int> &coins, int i , int amount, vector<vector<int>> &dp) {
		if (amount == 0)return 1;

		if (i == 0) {
			// if (amount < 0)
			// 	return 0;

			return 0;
		}

		if (dp[i][amount] != -1)return dp[i][amount];

		int take = amount >= coins[i - 1] ? sol(coins, i, amount - coins[i - 1], dp) : 0 ;
		int notTake = sol(coins, i - 1, amount, dp);

		return dp[i][amount] = take + notTake;

	}
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		//vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

		for (int i = 0; i <= n; ++i)dp[i][0] = 1;

		for (int i = 0; i <= amount; ++i)dp[0][i] = 0;

		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				if (i == 0) dp[i][j] = 0;
				if (j == 0) dp[i][j] = 1;
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int amt = 1; amt <= amount; ++amt) {


				int take = amount >= coins[i - 1] ? dp[i][amount - coins[i - 1]] : 0 ;
				int notTake = dp[i - 1][ amount];

				dp[i][amount] = take + notTake;
			}
		}
		//return sol(coins, n, amount, dp);
		return dp[n][amount];
	}
};