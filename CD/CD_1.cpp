
#include<bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	string s;
	cin >> s;
	int i = 0;
	int state = 0;
	int n = s.size();
	while (i < n)
	{
		switch (state)
		{
		case 0: if (s[i] == 'x')
				state = 1;
			else
				state = -1;
			break;
		case 1:
			if (s[i] == 'z')
				state = 2;
			else
				state = 1;
			break;
		case 2:
			if (i != n - 1)
				state = -1;
			break;

		};
		if (state = -1)
			break;
	}
	if (state != -1)
		cout << "passed\n";
	else
		cout << "Failed\n";

}