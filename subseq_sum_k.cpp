#include <bits/stdc++.h>

// int sol(int i , vector<int> num, int tar, vector<vector<int>> &dp)
// {
//     if (tar == 0)
//         return true;
//     if (i == 0)
//         return tar == num[0];
//     if (dp[i][tar] != -1)
//         return dp[i][tar];
//     bool take = 0;
//     if (tar >= num[i])
//         take = sol(i - 1, num, tar - num[i], dp);

//     bool not_take = sol(i - 1, num, tar, dp);
//     return dp[i][tar] = take | not_take;
// }

bool subsetSumToK(int n, int k, vector<int> &num) {
	// vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
//     vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));
//     for (int i = 0; i < n; ++i) dp[i][0] = true;
//     dp[0][num[0]] = true;
	vector<bool> prev(k + 1, false), curr(k + 1, false);
	prev[0] = curr[0] = true;
	prev[num[0]] = true;
	for (int i = 1; i < n; ++i)
	{


		for (int tar = 1; tar <= k; ++tar)
		{
			bool take = tar >= num[i] ? take = prev[tar - num[i]] : false;

			bool not_take = prev[tar];
			curr[tar] = take | not_take;
		}
		prev = curr;
	}
	//return sol(n, arr, k, dp);
	return prev[k];
}