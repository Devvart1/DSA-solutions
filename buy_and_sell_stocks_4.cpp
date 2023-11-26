class Solution {
public:
	int sol(vector<int> &prices, int i, int k, int buy, 	vector<vector<vector<int>>> &dp ) {
		if (i == prices.size() || k == 0) {
			return 0;
		}
		if (dp[i][k][buy] != -1)return dp[i][k][buy];
		if (buy) {
			return  dp[i][k][buy] = max((-prices[i] + sol(prices, i + 1, k, 0, dp)), sol(prices, i + 1, k, 1, dp));
		}
		else {
			return dp[i][k][buy] = max((prices[i] + sol(prices, i + 1, k - 1, 1, dp)), sol(prices, i + 1, k, 0, dp));
		}

		return 0;

	}
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
		return sol(prices, 0, k, 1, dp);
	}
};