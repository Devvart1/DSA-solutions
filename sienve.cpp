#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x;
bool sieve[1000000];

void make_sieve(int n) {

	for (int i = 3; i <= n; i += 2) {
		sieve[i] = true;
	}
	for (ll i = 3; i <= n; i += 2) {
		if (sieve[i])
		{	for (int j = i * i; j <= n; j += i) {
				sieve[j] = false;
			}
		}
	}
	sieve[2] = true;
	sieve[0] = sieve[1] = 0;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	memset(sieve, false, sizeof(sieve));
	int n;
	cin >> n;

	make_sieve(n);
	for (int i = 0; i <= n; ++i) {
		if (sieve[i])cout << i << " ";
	}


}