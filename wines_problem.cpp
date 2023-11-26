

#include<bits/stdc++.h>
using namespace std;

int sol(int i, int j, vector<int> &v, int y, vector<vector<int>> &dp)
{
	if (i > j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int a = v[i] * y + sol(i + 1, j, v, y + 1, dp);
	int b = v[j] * y + sol(i, j - 1, v, y + 1, dp);
	return dp[i][j] = max(a, b);



}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 0;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];

	}


	vector<vector<int>> dp(n, vector<int>(n, -1));
	dp[0][0] = v[0];
	dp[n - 1][n - 1]
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		}
	cout << sol(0, n - 1, v, 1, dp);
	return 0;
}

