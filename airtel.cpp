#include<bits/stdc++.h>

using namespace std;


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	int n;
	cin >> n;

	n = (int)pow(2, n) - 1;

	vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];

	}


	int node;
	cin >> node;


	int ind = 0;

	for (int i = 0; i < n; ++i) {
		if (v[i] == node)ind = 0;

	}

	vector<int> path;

	while (ind) {
		path.push_back(ind);
		ind /= 2;
	}

	reverse(begin(path), end(path));
	string ans = "";
	if (path[1] == 0) {
		ans += 'L';
	} else
		ans += 'R';
	int x = path.size();
	int i = 1;
	while (i < x) {
		if (path[i] % 2 == 0) {
			ans += 'R';
		}
		else
			ans += 'L';
	}

	cout << ans;
	return 0;



}