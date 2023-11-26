#include<bits/stdc++.h>
using namespace std;


int ans(int i, int j , int n, int m, vector<vector<int>>& grid, int z, int cz)
{
	if (i < 0 || j < 0  || i >= n || j >= m || grid[i][j] == -1)
		return 0;



	if (grid[i][j] == 2 )
	{
		if ((cz - 1) == z)
		{	return 1;
		}
	}
	grid[i][j] = -1;
	cz++;
	return ans(i - 1, j, n, m, grid, z, ans, cz) + ans(i, j - 1, n, m, grid, z, ans, cz ) + ans(i, j + 1, n, m, grid, z, ans, cz ) + ans(i + 1, j, n, m, grid, z, ans, cz );


	grid[i][j] = 0;

}

int uniquePathsIII(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	int i, j, a, b;
	int z = 0;
	for (i = 0; i < n; ++i)
	{
		for ( j = 0; j < m; ++j)
		{
			if (grid[i][j] == 1)
			{
				a = i;
				b = j;
			}
			else if (grid[i][j] == 0)
				z++;
		}
	}
	int ans = 0;
	return ans(i, j, n, m, grid, z, 0);
}