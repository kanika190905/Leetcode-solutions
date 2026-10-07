class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& g,
              vector<vector<int>>& dp) {

        if(i == g.size()-1 && j == g[0].size()-1){
            return max(1, 1 - g[i][j]);
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = INT_MAX, down = INT_MAX;

        if(i+1 < g.size())
            right = solve(i+1, j, g, dp);

        if(j+1 < g[0].size())
            down = solve(i, j+1, g, dp);

        int need = min(down, right) - g[i][j];

        return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, dungeon, dp);
    }
};