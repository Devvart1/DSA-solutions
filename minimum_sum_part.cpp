//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:

	// int min_dif(int arr[], int i, int sum, vector<vector<int>> &dp) {
	// 	if (sum == 0)return 1;
	// 	if (i == 0) {
	// 		return (arr[i] == sum);
	// 	}
	// 	if (dp[i][sum] != -1)return dp[i][sum];

	// 	int take = 0;
	// 	if (arr[i] <= sum)
	// 		take = min_dif(arr, i - 1, sum - arr[i], dp);

	// 	int notTake = min_dif(arr, i - 1, sum, dp);
	// 	return dp[i][sum] = take || notTake;
	// }


	// int minDifference(int arr[], int n)  {
	// 	// Your code goes here
	// 	int sum = 0;
	// 	for (int i = 0; i < n; ++i) {
	// 		sum += arr[i];
	// 	}

	// 	vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
	// 	int minn = INT_MAX;

	// 	for (int i = 0; i < n; ++i) {
	// 		dp[i][0] = 1;
	// 	}
	// 	if (arr[0] <= sum) {
	// 		dp[0][arr[0]] = 1;
	// 	}

	// 	for (int i = 1; i < n; ++i) {
	// 		for (int s = 0; s <= sum; ++s) {

	// 			int take = 0;

	// 			if (arr[i] <= s)
	// 				take = dp[i - 1][s - arr[i]];

	// 			int notTake = dp[i - 1][s];
	// 			dp[i][s] = take || notTake;
	// 		}
	// 	}
	// 	for (int i = 0; i <= sum; ++i) {
	// 		if (dp[n - 1][i]) {
	// 			minn = min(minn, abs(i - (sum - i)));
	// 		}
	// 	}
	// 	return minn;

	// }

	// void sol(vector<int> &arr, int i, vector<int>&subSum, int&currSum) {
	// 	if (i == 0) {
	// 		subSum.push_back(currSum);
	// 	}
	// 	currSum += arr[i];
	// 	sol(arr, subSum, currSum);
	// 	currSum -= arr[i];
	// 	sol(arr, subSum, currSum);
	// }
	int minDifference(int arr[], int n)  {
		// Your code goes here
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += arr[i];
		}

		//vector<int>curr(sum + 1, 0), prev(sum + 1, 0);
		unordered<int, int> prev, curr;
		int minn = INT_MAX;

		prev[0] = 1;
		if (arr[0] <= sum) {
			prev[arr[0]] = 1;
		}

		for (int i = 1; i < n; ++i) {
			for (int s = 0; s <= sum; ++s) {

				int take = 0;

				if (arr[i] <= s)
					take = prev[s - arr[i]];

				int notTake = prev[s];
				curr[s] = take || notTake;
			}
			prev = curr;
		}
		for (int i = 0; i <= sum; ++i) {
			if (prev[i]) {
				minn = min(minn, abs(i - (sum - i)));
			}
		}
		return minn;


	}


	// failed
// 	int minimumDifference(vector<int> &arr) {
// 		vector<int> subSum;
// 		int currSum = 0;
// 		int n = subSum.size();
// 		sol(arr, n - 1, subSum, currSum);

// 		sort(subSum.begin(), subSum.end());

// 		int minn = INT_MAX;
// 		for (int i = 0; i < n; ++i) {
// 			for (int j = i + 1; j < n; ++j) {

// 				minn = min(abs(subSum[i] - subSum[j]), minn);
// 			}
// 		}
// return minn;

// 	}

};


//{ Driver Code Starts.
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];



		Solution ob;
		cout << ob.minDifference(a, n) << "\n";

	}
	return 0;
}
// } Driver Code Ends