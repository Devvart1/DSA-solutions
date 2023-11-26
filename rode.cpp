
#include<bits/stdc++.h>
using namespace std;

int sol(int i, vector<int> price)
{
  if (i <= 0)
    return 1;
  int ans = 0;
  for (int x = 1; x <= k; ++x)
  {
    if ((i - x) >= 0)
      ans += ( sol(i - x, k));
  }
  return ans;

}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n = 0;
  cin >> n;
  int k ;
  cin >> k;
  int dp[n] = {0};
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= k; ++i)dp[i] =  2 * dp[i - 1];

  for (int i = k + 1 ; i <= n; ++i)
  {

    //if ((i - x) >= 0)
    dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
    cout << dp[i] << endl;


  }
  cout << sol()
       return 0;
}

