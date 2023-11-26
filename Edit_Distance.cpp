class Solution {
public:
	Solution() {
		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	}
	// int sol( string &word1, string &word2, int i , int j, vector<vector<int>> &dp) {


	// 	if (i == 0) {
	// 		return  j;
	// 	}
	// 	if (j == 0)
	// 		return i;
	// 	if (dp[i][j] != -1)return dp[i][j];

	// 	if (word1[i - 1] == word2[j - 1]) {
	// 		return dp[i][j] = sol(word1, word2, i - 1, j - 1, dp);
	// 	}
	// 	int ins = 1 + sol(word1, word2, i, j - 1, dp);
	// 	int del = 1 + sol(word1, word2, i - 1, j, dp);
	// 	int rep = 1 + sol(word1, word2, i - 1, j - 1, dp);
	// 	return dp[i][j] = min({ins, del, rep});

	// }
	int mindist(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		//vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i <= m; ++i) {
			dp[0][i] = i;
		}
		for (int i = 0; i <= n; ++i) {
			dp[i][0] = i;
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {


				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][ j], dp[i - 1][j - 1]});
				}



			}
		}


		return dp[n][m];

	}
};