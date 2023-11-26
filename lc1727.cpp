class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0 and matrix[i][j])
                    matrix[i][j] = +matrix[i - 1][j];
                vector<int> height = matrix[i];

                sort(height.begin(), height.end());
                for (int k = 0; k < j; ++k) {
                    int base = k + 1;
                    int h = height[k];
                    maxArea = max(maxArea, base * h);
                }
            }
        }
        return maxArea;
    }
};