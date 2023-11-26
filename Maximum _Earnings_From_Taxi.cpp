class Solution {
public:
	long long sol(int i, int prev, vector<vector<int>>& rides) {
		if (i == 0) {

			return rides[prev][1] <= rides[i][0] ? (rides[i][1] - rides[i][0] + rides[i]) : 0;

		}

		long long take =  rides[prev][1] <= rides[i][0] and prev > 0 ? rides[i][1] - rides[i][0] + rides[i][0] + sol(i - 1, i, rides) : rides[i][1] - rides[i][0] + rides[i][0];

		long long  ntake = sol(i - 1, prev, rides);
		cout << take << " " << ntake << endl;
		return max(take, ntake);
	}
	long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
		int ans = 0;
		int m = rides.size();
		map<int, vector<vector<int>>> m;
		for (auto x : rides)
		{
			m[x[1]].push_back(x);
		}
		sort(rides.begin(), rides.end(), comp);

		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n; ++i) {

			auto ride = m[i];
			if (ride.size() != 0) {
				long long earn = 0;

				for (auto x : ride) {
					earn = max(earn, x[1] - x[0] + x[2] + dp[x[0]]);
				}
				dp[i] = earn;
			}
			dp[i] = max(dp[i], dp[i - 1]);
		}
		return dp[n];

	}
};