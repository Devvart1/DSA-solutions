
int minOperations(vector<int>& nums) {
  unordered_map<int, int> m;
  for (auto x : nums)m[x]++;
  int n = nums.size();
  vector<int> n_arr;
  for (auto x : m)n_arr.push_back(x.first);
  int min_ans = INT_MAX;
  int len = n - 1;
  for (int i = 0; i < n_arr.size(); ++i)
  {
    int newmin = 0;
    for (int j = 0; j < n; ++j)
    {
      if (m[n_arr[i] + j] == 0)
      {
        newmin++;
      }
    }
    // cout<<newmin<<endl;
    min_ans = min(newmin, min_ans);
  }
  return min_ans;
}