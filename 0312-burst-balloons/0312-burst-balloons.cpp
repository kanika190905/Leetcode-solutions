class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // pad with 1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        // length of interval
        for(int len = 1; len <= n; len++){
            for(int i = 1; i <= n - len + 1; i++){
                int j = i + len - 1;

                for(int idx = i; idx <= j; idx++){
                    int cost = nums[i-1] * nums[idx] * nums[j+1]
                             + dp[i][idx-1]
                             + dp[idx+1][j];

                    dp[i][j] = max(dp[i][j], cost);
                }
            }
        }

        return dp[1][n];
    }
};