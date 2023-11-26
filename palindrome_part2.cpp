int dp[105][105][105];
int preCalc[105][105];

class Solution {
public:
	int minOpsToPali(string &s) {

		int ans = 0;
		int i = 0;
		int j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j]) {
				ans++;
			}
			i++;
			j--;
		}
		return ans;
	}

	int sol(string &s, int i, int j, int curr_k) {

		if (curr_k == 0) {
			if (i > j)return 0;
			else
				return 1e9;
		}
		if (i > j)return 1e9;

		if (dp[i][j][curr_k] != -1)return dp[i][j][curr_k];
		int &ans = dp[i][j][curr_k];

		ans = 1e9;
		for (int l = i; l <= j; l++) {
			ans = min(preCalc[i][l] + sol(s, l + 1, j, curr_k - 1), ans);

		}
		//cout << ans << " ";
		return ans;

	}
	int palindromePartition(string s, int k) {

		memset(dp, -1, sizeof dp);
		memset(preCalc, 0, sizeof preCalc);
		for (int i = 0; i < 105; i++)
			for (int j = 0; j < 105; j++)
				preCalc[i][j] = 1e9;

		int n = s.size();

		for (int i = 0; i < n; ++i) {
			string curr = "";
			for (int j = i; j < n; ++j) {
				curr += s[j];
				// cout<<curr<<" ";
				preCalc[i][j] = minOpsToPali(curr);

			}
		}

		int ans = sol(s, 0, n - 1, k);

		return ans;
	}
};