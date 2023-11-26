
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  bool sol(int i, int sum, vector<int> nums, vector<vector<int>> &dp)
  {
    if (sum == 0)
      return true;
    if (i == 0)
      return nums[0] == sum;

    if (dp[i][sum] != -1)
      return dp[i][sum];
    bool take = false;
    if ((sum - nums[i]) >= 0)
      take = sol(i - 1, sum - nums[i], nums, dp);
    bool ntake = sol(i - 1, sum, nums, dp);
    return dp[i][sum] = take | ntake;
  }
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
      sum += nums[i];
    }
    if (sum % 2 == 1)
      return false;
    vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, 0));

    sum = sum / 2;
    for (int i = 0; i < n; ++i)
    {
      for (int tar = sum; tar >= 0; ++tar)
      {

        bool take = (tar - nums[i]) >= 0 ? dp[i - 1][ sum - nums[i]] : false;
        bool ntake = dp[i - 1][sum];
        dp[i][sum] = take | ntake;
      }
    }
    return sol(n - 1, sum / 2, nums, dp);

  }
};

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif


  int x;
  cin >> x;
  for (int i = 0; i < )


  }
