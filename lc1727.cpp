//Approach-1 (Using sorting)
//T.C : (m * nlogn)
//S.C : O(m*n)
class Solution {
public:
    // int largestSubmatrix(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     int maxArea = 0;

    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < m; ++j) {

    //             if (i > 0 and matrix[i][j])
    //                 matrix[i][j] += matrix[i - 1][j];


    //         }
    //         vector<int> height = matrix[i];

    //         sort(height.begin(), height.end(), greater<int>());
    //         for (int k = 0; k < m; ++k) {
    //             int base = k + 1;
    //             int h = height[k];
    //             maxArea = max(maxArea, base * h);
    //         }
    //     }
    //     return maxArea;
    // }

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int>prev(m, 0);

        for (int i = 0; i < n; ++i) {
            vector<int>cur(m, 0);
            for (int j = 0; j < m; ++j) {

                if (matrix[i][j])
                    cur[j] = prev[j] + 1;

            }
            prev = cur;
            sort(cur.begin(), cur.end(), greater<int>());
            for (int k = 0; k < m; ++k) {
                int base = k + 1;
                int h = cur[k];
                maxArea = max(maxArea, base * h);
            }
        }
        return maxArea;
    }
};