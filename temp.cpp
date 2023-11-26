class Solution {
public:

	bool canPart(vector<int> &nums, int i, int sum) {
		if (sum == 0)
			return true;
		if (i == 0)
		{
			if (sum == nums[i])
				return true;

			return false;
		}

		bool take = canPart(nums, i - 1, sum - nums[i]);
		bool  unTake = canPart(nums, i - 1, sum);
		return take || unTake;

	}
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<bool>(sum + 1, 0));


		for (auto x : nums)sum += x;
		if (sum % 2)return false;


		for (int i = n - 1; i >= 0; --i) {
			for (int s = sum / 2; s >= 0; --s) {

				bool take = dp[i - 1] [sum - nums[i]];
				bool  unTake = dp[i - 1][ sum];

				dp[i][j] take || unTake;
			}
		}
		return dp[0][0];
	}
};