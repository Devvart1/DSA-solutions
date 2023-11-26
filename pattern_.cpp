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
	int k = -1;

	for (int i = 1; i <= n / 2 + 1; ++i) {
		if (i == 1)
		{
			for (int j = 1; j <= n; ++j) {

				cout << "* ";
			}
		} else {

			for (int j = 1; j <= n / i; ++j) {

				cout << "* ";
			}
			for (int j = 1; j <= n - 2 * (n / i) ; ++j)
				cout << "  ";
			k++;

			for (int j = 1; j <= n / i; ++j) {

				cout << "* ";
			}
		}
		cout << endl;


	}

	for (int i =  n / 2; i >= 1; --i) {

		if (i == 1)
		{
			for (int j = 1; j <= n; ++j) {

				cout << "* ";
			}
		} else {

			for (int j = n / i; j >= 1; --j) {

				cout << "* ";
			}
			for (int j =  n - 2 * (n / i); j >= 1; --j)
				cout << "  ";
			k++;
			for (int j = n / i; j >= 1; --j) {

				cout << "* ";
			}
		}
		cout << endl;


	}
	return 0;
}