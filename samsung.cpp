#include <bits/stdc++.h>
using namespace std ;
bool isValid(int i , int j , int n) {
	if (i >= 0 and j >= 0 and i < n  and j < n)return true;

	return false;
}
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
int sol(int i, int j, vector<vector<int>> &area, map<pair<int, int>, int> m, int n, int c) {

	queue<pair<int, int>> q;
	q.push({i, j});
	int count = 0;
	int dist = -1;
	int max_element_dist = INT_MIN;

	vector<vector<int>> vis(n, vector<int>(n, 0));

	while (q.size()) {
		int sije = q.size();
		dist++;

		while (sije--) {
			auto cur = q.front();
			int x = cur.first;
			int y = cur.second;

			if (m[ {x, y}] == 1) {
				m[ {x, y}] = dist;
				if (dist > max_element_dist) {
					max_element_dist = dist;
				}
				count++;
			}
			if (count == c)return max_element_dist;

			q.pop();
			for (int k = 0; k < 4; ++k) {
				int _i = x + dir[k][0];
				int _j = y + dir[k][1];
				if (isValid(_i, _j, n) and area[_i][_j] and vis[_i][_j] == 0) {
					q.push({_i, _j});
				}
			}

		}
	}
	return max_element_dist;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif


	int n, c;
	cin >> n >> c;

	map<pair<int, int>, int> m;
	for (int i = 0; i < c; ++i) {
		int x, y;
		cin >> x >> y;

		m[ {x, y}] = 1;
	}
	vector<vector<int>> area(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j  = 0 ; j < n; ++j) {
			cin >> area[i][j];
		}

	}
	int min_dist = INT_MAX;
	for (int i = 0; i < n; ++i) {
		for (int j  = 0 ; j < n; ++j) {
			if (area[i][j] == 0)continue;

			int max_element_dist = sol( i,  j, area, m, n, c);
			if (max_element_dist < min_dist) {
				min_dist = max_element_dist;
			}
		}
	}

	return min_dist;

	return 0;
}