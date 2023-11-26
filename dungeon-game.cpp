//

class Solution {
public:
	// int sol(vector<vector<int>> &dungeon, int i, int j, int n, int m) {

	// 	if (i < 0 || j < 0 || i >= n || j >= m) {
	// 		return 1e9;

	// 	}

	// 	if (i == n - 1 and j == m - 1) {
	// 		if (dungeon[i][j] > 0)return 1;
	// 		else return 1 - dungeon[i][j] ;
	// 	}
	// 	if (dp[i][j] != -1)return dp[i][j];

	// 	int health = min(sol(dungeon, i, j + 1, n, m), sol(dungeon, i + 1, j, n, m));
	// 	if (health == 1e9)
	// 		health = 1;
	// 	int res = 0;
	// 	if (health - dungeon[i][j] > 0) {
	// 		res = health - dungeon[i][j];
	// 	}
	// 	else
	// 		res = 1;

	// 	return dp[i][j] = res;
	// }
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int n = dungeon.size();
		int m = dungeon[0].size();
		int dp[n][m] = {{0}};

		dp[n - 1][m - 1] = dungeon[n - 1][m - 1] > 0 ? 1 : 1 - dungeon[n - 1][m - 1];

		for (int i = n - 2; i >= 0; --i)
			dp[i][m - 1] = max(dp[i + 1][m - 1] - dungeon[i][m - 1], 1);



		for (int j = m - 2; j >= 0; --j)
			dp[n - 1][j] = max(dp[n - 1][j + 1] - dungeon[n - 1][j], 1);

		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = m - 2; j >= 0; --j) {
				dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);

			}
		}


		return dp[0][0];





		//return sol(dungeon, 0, 0, n, m);
	}
};