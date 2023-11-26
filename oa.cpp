#include <bits/stdc++.h>
using namespace std ;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int n, x;
	cin >> n >> x;
	int maxx = 0;
	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			maxx = max(v[i][j], maxx);
		}

	}

	vector<int> mult;
	mult.push_back(0);
//  	mult.push_back(1);
	int xx = 1;
	int i = 1;
	while (xx <= maxx) {

		xx = x * i;
		mult.push_back(xx);
		i++;
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			auto xxx = lower_bound(mult.begin(), mult.end(), v[i][j]) - mult.begin();
			if (mult[xxx] > v[i][j])xxx--;
			v[i][j] = mult[xxx];
			cout << mult[xxx] << " ";
		}
		cout << endl;

	}



	return 0;
}