

class Solution {
public:
  int sol(vector<int> &num) {
    int n = num.size();


    int prev = 0;
    int prev2 = num[0];


    for (int i = 1; i <= n; ++i) {

      int take = (i > 1) ? num[i - 1] + prev2 : num[i - 1];
      int untake = prev;
      int curr = max(take, untake);

      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
  int rob(vector<int>& nums) {

    int n = nums.size();
    if (n == 1)return nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; ++i) {
      if (i != 0)temp1.push_back(nums[i]);
      if (i != n - 1) temp2.push_back(nums[i]);
    }
    return max(sol(temp1), sol(temp2));
  }
};