class Solution {
public:
    int sol(vector<int> &cost, int i) {
        if (i < 0)return 0;
        if (i == 0 || i == 1)
            return cost[i];

        int one = cost[i] + sol(cost, i - 1);
        int two = cost[i] + sol(cost, i - 2);

        return min(one, two) ;

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        return min(sol(cost, n - 1), sol(cost, n - 2));

    }
};