#include <bits/stdc++.h>
using namespace std ;


int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// #ifndef ONLINE_JUDGE
// 	freopen("Error.txt", "w", stderr);
// #endif

	string s;
	// cin >> s;
	s = "000110";
	int n = s.size();

	int ans = 0;
	// cout << "ss";
	int zero = 0;
	int one = 0;

	int i , j;
	i = j = 0;

	vector<int> temp;



	while (j < n) {
		// cout << "ss";

		if (s[j] == '0') {
			zero = 0;
			while (j < n and s[j] == '0')
			{
				zero++; j++;
			}
			temp.push_back(zero);
		}

		if (s[j] == '1') {
			one = 0;
			while (j < n and s[j] == '1')
			{
				one++; j++;
			}
			temp.push_back(one);
		}
	}

	for (int i = 0; i < temp.size() - 1; ++i) {
		ans += min(temp[i], temp[i + 1]);
	}

	cout << ans;
	return 0;
}