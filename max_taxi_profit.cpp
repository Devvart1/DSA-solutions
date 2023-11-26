class Solution {
public:
    int upperBound(vector<vector<int>> &rides, int s , int e , int startValue) {

        int ans = e + 1 ;

        while (s <= e) {
            int mid = (s + e) / 2 ;

            if (rides[mid][1] > startValue) {
                ans = mid ;
                e = mid - 1 ;
            }
            else {
                s = mid + 1 ;
            }
        }

        return ans ;
    }

    static bool cmp(vector<int> &A , vector<int> &B) {

        return A[1] < B[1] ;
    }

    long long maxTaxiEarnings(int k, vector<vector<int>>& rides) {

        sort(rides.begin() , rides.end(), cmp) ;

        int n = rides.size() ;

        vector<long long> dp(n) ;

        dp[0] = rides[0][1] - rides[0][0] + rides[0][2];

        for (int i = 1 ; i < n ; i++) {

            long long int PrevProfitIdxByIncluding = upperBound(rides, 0 , i - 1 , rides[i][0]) - 1  ;
            long long int maxPrevProfitByIncluding = PrevProfitIdxByIncluding >= 0 ? dp[PrevProfitIdxByIncluding] : 0 ;

            dp[i] = rides[i][1] - rides[i][0] + rides[i][2] + maxPrevProfitByIncluding  ;
            if (dp[i - 1] > dp[i]) {
                dp[i] = dp[i - 1] ;
            }
        }

        return dp[n - 1] ;
    }
};

