#define ll int
ll dp[505][505];
class Solution {
public:
	// turn = 0 alice
	// 1 bob
	ll func(ll i, ll j, ll turn, vector<ll>&arr)
	{
		if (i > j)return 0;
		if (dp[i]j] != -1)return dp[i][j];
			if (turn) {
			return dp[i][j] = max(arr[i] + func(i + 1, j, turn ^ 1, arr), arr[j] + func(i, j - 1, turn ^ 1, arr));
			}
			else {
				return dp[i][j] = min(func(i + 1, j, turn ^ 1, arr), func(i, j - 1, turn ^ 1, arr));
			}
	}
	bool PredictTheWinner(vector<int>& piles) {
		memset(dp, -1, sizeof dp);

		int n = piles.size();
		long long sum = 0;
		for (auto x : piles)sum += x;
		int ans = func(0, n - 1, 1, piles);
		sum -= ans;


		return ans >= sum;
	}
};