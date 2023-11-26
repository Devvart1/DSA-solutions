
#include <bits/stdc++.h>
using namespace std;

// void sol(vector<vector<int>> &m,vector<string> &ans,vector<vector<int>> &v,string &out, int i,int j,int n)
// {
//     if(i==n-1&&j==n-1)
//     {
//         ans.push_back(out);
//         return;
//     }

//     if(i+1<=n-1&& m[i+1][j]==1&&v[i+1][j]!=1)
//     {
//         v[i][j]=1;

//       sol(m,ans,v,out +'D',i+1,j,n);
//       v[i][j]=0;

//     }
//      if(j+1<=n-1&& m[i][j+1]==1&&v[i][j+1]!=1)
//     {
//         v[i][j]=1;

//       sol(m,ans,v,out +'R',i,j+1,n);
//       v[i][j]=0;

//     }
//      if(i>0&& m[i-1][j]==1&&v[i-1][j]!=1)
//     {
//         v[i][j]=1;

//       sol(m,ans,v,out +'U',i-1,j,n);
//       v[i][j]=0;

//     }
//      if(j>0&& m[i][j-1]==1&&v[i][j-1]!=1)
//     {
//         v[i][j]=1;

//       sol(m,ans,v,out +'L',i,j-1,n);
//       v[i][j]=0;

//     }
// }

// void solloop(vector<vector<int>> &m,vector<string> &ans,vector<vector<int>> &v,string out, int i,int j,int n,vector<int> di,vector<int> dj)
// {
//     if(i==n-1&&j==n-1)
//     {
//         ans.push_back(out);
//         return;
//     }

//     string x="DRUL";
//     for(int z =0;z<4;++z)
//     {
//           int ni=i + di[z];
//     int nj=j+dj[z];
//         if(ni<n&&nj<n&& m[ni][nj]==1&&v[ni][nj]!=1 &&ni>=0&&nj>=0)
//         {
//              v[i][j]=1;

//       solloop(m,ans,v,out +x[z],ni,nj,n,di,dj);
//       v[i][j]=0;
//         }
//     }
// }

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
           vector<vector<int>> &vis, int di[], int dj[])
{
  if (i == n - 1 && j == n - 1)
  {
    ans.push_back(move);
    return;
  }
  string dir = "DLRU";
  for (int ind = 0; ind < 4; ind++)
  {
    int nexti = i + di[ind];
    int nextj = j + dj[ind];
    if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1)
    {
      vis[i][j] = 1;
      solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
      vis[i][j] = 0;
    }
  }
}
vector<string> findPath(vector<vector<int>> &m, int n)
{

  string out;
  vector<string> ans;

  //  int  di[]={1,0,-1,0};
  //     int dj[]={0,1,0,-1};

  int di[] = {
      +1,
      0,
      0,
      -1};
  int dj[] = {
      0,
      -1,
      1,
      0};

  vector<vector<int>> vis(n, vector<int>(n, 0));
  // if(m[0][0]==1)
  // solloop(m,ans,vis,"",0,0,n,di,dj);
  if (m[0][0] == 1)
    solve(0, 0, m, n, ans, "", vis, di, dj);
  return ans;
}



int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> m[i][j];
      }
    }

    vector<string> result = findPath(m, n);
    sort(result.begin(), result.end());
    if (result.size() == 0)
      cout << -1;
    else
      for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}
