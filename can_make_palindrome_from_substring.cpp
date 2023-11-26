class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> m(n, vector<int>(26, 0));

        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                m[i][s[i] - 'a']++;

            }
            else
            {
                for (int j = 0; j < 26; ++j) {
                    m[i][j] = m[i - 1][j];
                }
                m[i][s[i] - 'a']++;

            }
            // for (int j = 0; j < 26; ++j) {
            //     cout << m[i][j] << " ";
            // }
            // cout << endl;

        }
        n = queries.size();
        vector<bool> ans(n, 1);
        int x = 0;

        for (int i = 0; i < n; ++i) {

            x = 0;

            int left = queries[i][0];
            int right = queries[i][1];
            int k = queries[i][2];
            if (left == 0) {
                for (int j = 0; j < 26; ++j) {


                    if (m[right][j] % 2) {
                        x++;
                    }
                }
            }
            else {
                for (int j = 0; j < 26; ++j) {


                    if ((m[right][j] - m[left - 1][j]) % 2) {
                        x++;
                    }

                }
            }

            if (x / 2 > k) {
                ans[i] = 0;
            }
        }

        return ans;
    }
};


bool checkValidString(string s) {
    int open = 0, close = 0;
    for (auto x : s) {
        if (x == ')')
            open--;
        else
            open++;
        if (open < 0)
            return false;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '(')
            close--;
        else
            close++;
        if (close < 0)
            return false;
    }
    return true;
}