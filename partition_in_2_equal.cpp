

#include<bits/stdc++.h>
using namespace std;


bool sol(int i, vector<int> arr, int tar)
{
  if (tar == 0)
    return true;

  if (i == 0)
  {
    return arr[0] == tar;
  }

  bool take = arr[i] >= tar ? sol(i + 1, arr, tar - arr[i]) : false;

  bool not_take = sol(i + 1, arr, tar);

  return take | not_take;
}
int minimumDifference(vector<int>& arr) {
  int n = arr.size();
  int totsum = 0;
  for (int x : arr) totsum += x;

  int min_diff = 1e8;

  for (int i = 0; i <= totsum / 2; i++)
  {
    if (sol(n - 1, arr, i) == true)
    {

      min_diff = min(abs(totsum - 2 * i) , min_diff);
    }
  }
  return min_diff;

//  return sol(n-1,arr,tar);

}


int minSubsetSumDifference(vector<int>& arr, int n)
{
  int totsum = 0;
  for (auto x : arr) totsum += x;


  //  vector<vector<bool>> dp(n,vector<bool>(totsum+1,0));
  vector<bool> prev(totsum + 1, false);
  // for(int i=0;i<n;++i) dp[i][0]=true;


  if (arr[0] <= totsum)
    prev[arr[0]] = true;
  //dp[0][arr[0]]=true;

  prev[0] = true;
  for (int i = 1; i < n; ++i)
  {
    vector<bool> curr(totsum + 1, false);
    curr[0] = true;
    for (int tar = 1; tar <= totsum; ++tar)
    {
      int notake = curr[tar];
      int take = (tar >= arr[i]) ? prev[tar - arr[i]] : false;


      curr[tar] = take || notake;

    }
    prev = curr;
  }

  int min_diff = 1e8;

  for (int i = 0; i <= totsum / 2; i++)
  {
    if (prev[i] == true)
    {

      min_diff = min(abs(totsum - 2 * i) , min_diff);
    }
  }
  return min_diff;
}