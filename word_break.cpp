
class Solution {
public:

   bool wordBreak(string s, vector<string>& wordDict) {
      int n = s.size();
      vector<int>dp(n, 0);
      unordered_map<string, int> m;
      for (auto x : wordDict) { m[x] = 1;}
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < i; ++j) {
            string temp = s.substr(j, i + 1);
            if (m[temp]) {
               if (j > 0)
                  dp[i] += dp[j - 1];
               else
                  dp[i] += 1;
            }

         }
      }
      return dp[n - 1] > 0;
   }
};

