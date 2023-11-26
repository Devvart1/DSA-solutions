class Solution {
public:
	int lcs(string s, string r, int i, int j) {

		if (i < 0 || j < 0)
			return 0;

		if (s[i] == r[j]) {
			return 1 + lcs(s, r, i - 1, j - 1);
		}
		else {
			return max(lcs(s, r, i - 1, j), lcs(s, r, i, j - 1));
		}
		return 0;

	}
	int longestPalindromeSubseq(string s) {
		string r = s;
		reverse(r.begin(), r.end());

		int n = s.size();
		int m = r.size();

// lcs of reversed string and original string will be the longestPalindromeSubseq
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (s[i - 1] == r[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][ j - 1];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[n][m];

	}
};