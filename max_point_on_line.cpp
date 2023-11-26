int maxPoints(vector<vector<int>>& p) {
  int n = points.size();
//map<float, int> m;
  int max_p = INT_MIN;
  int ans = 2;
  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = i; j < n; ++j)
    {
      max_p = 2;
      for (int k = 0; k < n; ++k)
      {

        if (k != i and k != j)
        {
          if ((p[j][1] - p[i][1]) * (p[jk[0] - p[i][0]) == (p[k][1] - p[i][1]) * (p[k][0] - p[i][0]))
              max_p++;

        }
    }
    max_p = max(max_p, ans);
    }
  }


  // for (auto x : m)
  // {
  //   max_p = max(max_p, x.second);
  // }
  //   return max_p;
  return ans;
}