

#include<bits/stdc++.h>
using namespace std;

int sol(int i, vector<int> &v, int tar)
{

	if (tar == 0)
		return 1;
	if (i == 0)
	{
		return (v[0] == tar) ? 1 : 0;
	}

	int take = v[i] <= tar ? (1 + sol(i - 1, v, tar - v[i])) : -100000;
	int not_take = sol(i - 1, v, tar);
	return max(take, not_take);

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 0;
	cin >> n;
	int tar;
	cin >> tar;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];

	}

	cout << sol(n - 1, v, tar);
	return 0;
}

