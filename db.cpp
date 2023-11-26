#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> path;

int sol(int i, int j , vector<vector<int>> &grid, vector<vector<bool>> &vis, int n, int m, int k ) {
	if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j]) {
		return 0;
	}

	vis[i][j] = true;

	int op1 =  grid[i][j] * k + sol(i + 1, j, grid, vis, n, m, k + 1);
	int op2 =  grid[i][j] * k + sol(i , j + 1, grid, vis, n, m, k + 1);
	int op3 =  grid[i][j] * k + sol(i - 1, j, grid, vis, n, m, k + 1);
	int op4 =  grid[i][j] * k + sol(i , j - 1, grid, vis, n, m, k + 1);

	if (op1 > op2 and op1 > op3 and op1 > op4) {
		path.push_back({i + 1, j});
	} else if (op2 > op1  and op2 > op3 and op2 > op4) {
		path.push_back({i, j + 1});
	} else if (op3 > op2  and op3 > op1 and op3 > op4) {
		path.push_back({i - 1, j});
	} else {
		path.push_back({i, j - 1});
	}
	return max({op1, op2, op3, op4});



}
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	path.push_back({0, 0});

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}

	cout << sol(0, 0, grid, vis, n, m, 0) << endl;
	cout << endl;
	for (auto x : path) {
		cout << "(" << x.first << "," << x.second << ")" << "->";
	}
	return 0;
}
