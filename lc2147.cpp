class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        if (n <= 1)return 0;
        long long ans = 1;
        int m = 1e9 + 7;
        int prev = -1;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S')
            {
                s++;
                if (prev == -1) {
                    prev = i;
                } else if (s % 2 == 0) {
                    prev = i;
                } else {
                    ans = (ans * (i - prev)) % m;
                }
            }
        }
        if (s == 0 || s % 2)return 0;

        return ans;
    }
};