class Solution {
public:

    vector<vector<int>> dir = {{1, 1}, {1, 0}, {0, 1}, { -1, -1}, { -1, 0}, {0, -1}, { -1, 1}, {1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 0 ||  m == 0 || grid[0][0] == '1')return -1;

        auto isSafe = [&](int x, int y) {
            return (x >= 0  and y >= 0 and y <= m - 1 and  x <= n - 1);

        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int level = 0;
        while (q.size()) {

            int N = q.size();
            while (N--) {
                auto  curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if (x == n - 1 and y == m - 1)return level + 1;

                for (auto d : dir) {
                    int x_ = x + d[0];
                    int y_ = y + d[1];

                    if (isSafe(x_, y_) and grid[x_][y_] == 0) {
                        q.push({x_, y_});
                        grid[x_][y_] = 1;
                    }

                }

            }
            level++;


        }

        return -1;

    }
};



class Solution {
public:
    long long check(long long a, int index, int n) {
        long long leftOffset = std::max(a - static_cast(index), 0LL);
        long long result = (a + leftOffset) * (a - leftOffset + 1) / 2;
        long long rightOffset = std::max(a - static_cast((n - 1) - index), 0LL);
        result += (a + rightOffset) * (a - rightOffset + 1) / 2;
        return result - a;
    }

    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (check(mid, index, n) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left + 1;
    }
};