#include <bits/stdc++.h> 
using namespace std;

 int sol(int i ,int j, int k,int r,int c, vector<vector<int>> grid,vector<vector<vector<int>>> &dp)
 {

    if(i>=r || j>=c|| k>=c || j<0 || k<0) return -1e8;
    if(i==r-1 and j==k) return grid[i][k];
    else if(i==r-1) return grid[i][j]+ grid[i][k];
  if(dp[i][j][k]!=-1)
  return dp[i][j][k];
int ans_max=-1e8;
    for(int d=-1;d<=1;++i)
    {
        for(int f=-1;f<=1;++f)
        {
            int val=0;
              val=(j==k)?grid[i][k]:grid[i][k]+ grid[i][j];
                  val+=sol(i+1,j+d,k+f,r,c,grid,dp);
                  ans_max=max(ans_max,val);
        }
    }
    return dp[i][j][k]= ans_max;
 }

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    //dp of dp[r][c][c]
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));



    for()
   return sol(0,0,c-1,r,c,grid,dp); 
}