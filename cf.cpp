#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;

		string s;
		cin >> s;
		int l, r;
		l = r = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'L')
				l++;
			else
				r++;
		}
		if (l == 0 || r == 0)
			cout << -1;
		else
		{
			int f = 0;
			for (int i = 0; i < n - 1; ++i)
			{
				if (s[i] == 'R' and s[i + 1] == 'L')
					f = 1;

			}
			if (f)
				cout << 0;
			else
				cout << 1;

		}
		cout << endl;
	}
	return 0;
}