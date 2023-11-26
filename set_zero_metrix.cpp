

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  // vector<int> row(n,1);
  // vector<int> col(m,1);

  bool rone = 1;
  bool cone = 1;
  int i, j;
  for (int j = 0; j < n; ++j)
  {

    if (matrix[j][0] == 0)
      rone = 0;


  }
  for (int j = 0; j < m; ++j)
  {

    if (matrix[0][j] == 0)
      cone = 0;

  }


  for (i = 1; i < n; ++i)
  {



    for (j = 1; j < m; ++j)
    {

      if (matrix[i][j] == 0)
      {
        matrix[0][j] = matrix[i][0] = 0;

      }
    }
  }

  for (int i = 1; i < n; ++i)
  {

    for (int j = 1; j < m; ++j)
    {
      if (matrix[0][j] == 0 || matrix[i][0] == 0)
        matrix[i][j] = 0;
    }
  }

  if (rone == 0)
  {
    for (int j = 0; j < n; ++j)
    {

      matrix[j][0] = 0;

    }
  }
  if (cone == 0)
  {
    for (int j = 0; j < m; ++j)
    {

      matrix[0][j] = 0;

    }
  }



}




int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(m, vector<int>(m));
  int i, j;
  for (i = 0; i < n; ++i)
  {



    for (j = 0; j < m; ++j)
    {
      //  if(matrix[0][i])
      cin >> v[i][j];
    }
  }
  setZeroes(v);
  for (i = 0; i < n; ++i)
  {



    for (j = 0; j < m; ++j)
    {
      //  if(matrix[0][i])
      cout << v[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

