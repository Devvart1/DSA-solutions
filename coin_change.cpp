class Solution {
public:

    int sol(vector<int> &coins, int amount, int i) {
        if (amount == 0)return 1;
        if (i == 0) {
            return -1;
        }

        int take = 0;
        if (coins[i] <= amount) {
            take =
        }
        int untake = sol(coins, amount, i - 1);

        return min(take, untake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        return sol(coins, amount, n);
    }
};