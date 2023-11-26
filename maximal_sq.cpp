class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();

		vector<vector<int>> dp(n, vector<int>(m, 0));

		for (int i = 0; i < n; ++i) {

			dp[i][0] = matrix[i][0] - '0';
		}
		for (int i = 0; i < m; ++i) {
			dp[0][i] = matrix[0][i] - '0';
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				if (matrix[i][j] == '1')
					dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
				else dp[i][j] = 0;
			}
		}

		return dp[n - 1][m - 1];



	}
};





