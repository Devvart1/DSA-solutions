//494 lc

class Solution {
public:
	int sol(int i , vector<int> &arr, int tar, vector<vector<int>> &dp)
	{
		if (i == 0)
		{
			if (tar == 0 and arr[0] == 0)
				return 2;
			if (tar == 0 || arr[0] == tar )
				return 1;
			return 0;

		}
		if (dp[i][tar + 2000] != -1)
			return dp[i][tar + 2000];
		int take = arr[i] <= tar ? sol(i - 1, arr, tar - arr[i], dp) : 0;
		int ntake = sol(i - 1, arr, tar, dp);

		return dp[i][tar + 2000] = (take + ntake);
	}
	int findTargetSumWays(vector<int>& num, int target) {
		int n = num.size();
		int totsum = 0;
		for ( int x : num)totsum += x;
		vector<vector<int>> dp(n, vector<int>(target + 2001, -1));

		return sol(n - 1, num, (totsum - target) / 2, dp);

	}
};


////////////////////////////////////////////////////////////
int findTargetSumWays(vector<int>& nums, int target) {
	int n = nums.size();
	int count = 0;
	int totalSum = 0;
	for (int i = 0; i < n; i++)
	{	if (nums[i] == 0)
		{
			count++;
		}
		totalSum += nums[i];
	}

	int sum = (target + totalSum) / 2;
	if ((totalSum + (long)target) % 2 == 1 || totalSum < target) return 0;
	int  dp[n + 1][sum + 1];
	int i = 0;
	for ( i = 0; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 1;
			}
			else if (i == 0)
			{
				dp[i][j] = 0;
			}
			else if (nums[i - 1] > j || nums[i - 1] == 0)
			{

				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
			}
		}
	}

	return pow(2, count) * dp[n][sum];
}