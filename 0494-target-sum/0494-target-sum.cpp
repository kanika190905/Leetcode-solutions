class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;

        for(int x : nums)
            sum += x;

        if(target > sum || target < -sum)
            return 0;

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

        dp[n][sum] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = -sum; j <= sum; j++) {
                int add = 0;
                int sub = 0;

                if(j - nums[i] >= -sum && j - nums[i] <= sum)
                    add = dp[i + 1][j - nums[i] + sum];

                if(j + nums[i] >= -sum && j + nums[i] <= sum)
                    sub = dp[i + 1][j + nums[i] + sum];

                dp[i][j + sum] = add + sub;
            }
        }

        return dp[0][target + sum];
    }
};