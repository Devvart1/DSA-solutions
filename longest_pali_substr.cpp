class Solution {
public:

	// void print_str(vector<vector<int>> &dp, int, i, int j, string &ans, int prev) {

	// 	if (i < 0 || j < 0 ) {
	// 		return ;
	// 	}






	// }
	// int lc_str(string &s, string &r, int i , int j) {
	// 	if (i == 0 || j == 0) {
	// 		return 0;
	// 	}
	// 	if (s[i] == s[j]) {
	// 		return 1 + lc_str(s, r, i - 1, j - 1);
	// 	}
	// 	else
	// 		return lc_str(s, r, i - 1, j - 1);
	// }

	string longestPalindrome(string s) {
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
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}


		string ans = "";
		int maxx = 0;
		int in_s = 0;
		int in_r = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (maxx < dp[i][j]) {
					maxx = dp[i][j];
					in_r = j;
					in_s = i;
				}
			}

		}

		while (maxx--) {

			if (s[in_r - 1] == r[in_r - 1]) {
				ans += s[in_r - 1];
			}
			else {
				ans += r[in_r - 1];
			}

			in_r--;
			in_s--;
		}
		return ans;




	}
};