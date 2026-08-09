class Solution {
public:
    int helper(int i, int m, vector<int>& piles, vector<vector<int>>& dp, vector<int>& suffix) {
        if (i >= piles.size()) return 0;

        if (dp[i][m] != -1) return dp[i][m];

        int maxi = 0;

        for (int j = 1; j <= 2 * m && i + j <= piles.size(); j++) {
            int opponent = helper(i + j, max(m, j), piles, dp, suffix);
            int current = suffix[i] - opponent;

            maxi = max(maxi, current);
        }

        return dp[i][m] = maxi;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(0, 1, piles, dp, suffix);
    }
};