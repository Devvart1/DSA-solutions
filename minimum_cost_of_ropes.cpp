//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
	//Function to return the minimum cost of connecting the ropes.
	long long minCost(long long arr[], long long n) {

		priority_queue<long long > pq;

		for (int i = 0; i < n; ++i)pq.push(arr[i]);
		if (n == 1)return arr[0];
		long long ans = 0;
		while (!pq.empty()) {

			int x = pq.front();
			pq.pop();
			int y = pq.front();
			pq.pop();
			ans += (x + y);
			pq.push(ans);
		}
		return ans;

	}
};


//{ Driver Code Starts.

int main() {
	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long i, a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		Solution ob;
		cout << ob.minCost(a, n) << endl;
	}
	return 0;
}

// } Driver Code Ends