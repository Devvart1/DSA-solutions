
#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
{
  vector<int> ans;
  int max_row = r - 1;
  int max_col = c - 1;
  int min_row = 0;
  int min_col = 0;


  while (min_col <= max_col and min_row <= max_row)
  {

    for (int i = min_col; i <= max_col ; ++i)
    {
      ans.push_back(matrix[min_row][i]);
      // cout << matrix[min_row][i];
    }
    min_row++;

    for (int j = min_row; j <= max_row; ++j)
    {
      ans.push_back(matrix[j][max_col]);
      // cout << matrix[j][max_col];
    }
    max_col--;

    if (min_row <= max_row and min_col <= max_col )
    {
      for (int j = max_col ; j >=  min_col; --j)
      {
        ans.push_back(matrix[max_row][j]);
        //  cout << matrix[max_row][j];
      }
      max_row--;

      for (int j = max_row ; j >= min_row; --j)
      {
        ans.push_back(matrix[j][min_col]);
        // cout << matrix[j][min_col];
      }
      min_col++;
    }
    // min_row++;
    //  max_col--;
    //  min_col++;
    //  max_row--;
  }
  return ans;
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
  vector<int> xx = spirallyTraverse(v, n, m);
// setZeroes(v);
  for (i = 0; i < n * m; ++i)
  {




    cout << xx[i] << " ";

  }

  return 0;
}
