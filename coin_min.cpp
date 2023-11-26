int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();
  //    vector<vector<int>> dp(n,vector<int>(amount+1,-1));

  vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
  for (int i = 0; i <= amount; ++i)
  {
    if (i % coins[0] == 0)
      dp[0][i] = i / coins[0];
    else
      dp[0][i] = 1e9;
  }

  for (int i = 0; i < n; ++i)
  {
    for (int a = 0; a <= amount; ++a)
    {
      int not_take = dp[i - 1][a];
      int take = (coins[i] <= a) ? (1 + dp[i][a - coins[i]]) : 1e9;
      dp[i][a] = min(not_take, take);
    }
  }
  int x = dp[n - 1][amount];

  if (x >= 1e9)
    return -1;
  else
    return x;
}