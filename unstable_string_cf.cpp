

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{

		string s;
		cin >> s;
		ll n = s.size();

		ll ans = 0;

		ll i = 0;

		ll last0 = -1;
		ll last1 = -1;
		ll invrt = 0;
		for (i = 0; i < n; ++i)
		{
			if (s[i] == '?')
				ans += (i - min(last0, last1));
			else
			{
				int cur = s[i] - '0';
				//cout << cur << endl;
				invrt = (i % 2) ^ cur;

				if (invrt == 0)
				{

					last0 = i;
					ans += (i - last1);
				}
				else
				{
					last1 = i;
					ans += (i - last0);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
