class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));

        // amount = 0 needs 0 coins
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int amt = 1; amt <= amount; amt++) {

                int notTake = dp[i - 1][amt];

                int take = 1e9;

                if (coins[i - 1] <= amt)
                    take = 1 + dp[i][amt - coins[i - 1]];

                dp[i][amt] = min(take, notTake);
            }
        }

        if (dp[n][amount] >= 1e9)
            return -1;

        return dp[n][amount];
    }
};