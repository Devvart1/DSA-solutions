#include <bits/stdc++.h>
using namespace std ;



bool isRaisingNumber(int num) {
	while (num > 0) {
		int lastDigit = num % 10;
		num /= 10;
		int nextDigit = num % 10;
		if (nextDigit > lastDigit) {
			return false;
		}
	}
	return true;
}
bool isDroppingNumber(int num) {
	while (num > 0) {
		int lastDigit = num % 10;
		num /= 10;
		int nextDigit = num % 10;
		if (nextDigit < lastDigit) {
			return false;
		}
	}
	return true;
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
	int drop, rais, non;
	rais = drop = non = 0;

	for (int i = n; i < m; ++i) {
		if (isRaisingNumber(i)) {
			rais++;
			cout << " r= " << i;
		} else if (isDroppingNumber(i)) {
			drop++;
			cout << " d= " << i;
		} else {
			cout << " non= " << i;
			non++;
		}
	}

	cout << rais << " " << drop << " " << non;
	return 0;
}