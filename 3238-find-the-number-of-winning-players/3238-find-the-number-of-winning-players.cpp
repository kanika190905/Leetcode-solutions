class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> cnt(n, vector<int>(11, 0));
        int ans = 0;

        for (auto &p : pick) {
            int player = p[0];
            int color = p[1];

            cnt[player][color]++;
        }

        vector<int> win(n, 0);

        for (auto &p : pick) {
            int player = p[0];
            if (cnt[player][p[1]] > player) {
                win[player] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            ans += win[i];
        }

        return ans;
    }
};