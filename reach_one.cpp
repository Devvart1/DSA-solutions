

#include<bits/stdc++.h>
using namespace std;

int sol(int n)
{
	int dp[n] = {0};

	dp[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		int o1, o2, o3;
		o1 = o2 = o3 = INT_MAX;

		if (i % 3 == 0)
			o1 = dp[i / 3];
		if (i % 2 == 0)
			o2 = dp[i / 2];
		o3 = dp[i - 1];

		dp[i] = min(min(o1, o2), o3) + 1;

	}
	return dp[n];

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 0;
	cin >> n;
	// int tar;
	// cin >> tar;
	// vector<int> v(n);
	// for (int i = 0; i < n; ++i)
	// {
	// 	cin >> v[i];

	// }

	cout << sol(n);
	return 0;
}

