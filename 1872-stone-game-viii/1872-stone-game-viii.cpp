#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<long long> dp;
    vector<int> prefix;
    int n;

    int solve(int i) {
        // Base case: forced to take the last remaining prefix
        if (i == n - 1) return prefix.back();
        
        // Check if we have visited this state (using our impossible value)
        if (dp[i] != 1e18) return dp[i];
        
        // Option A: Take the prefix at index 'i'
        int take = prefix[i] - solve(i + 1);
        
        // Option B: Skip index 'i', leaving it for later
        int skip = solve(i + 1);
        
        // Both players play optimally to maximize their difference
        dp[i] = max(take, skip);
        return dp[i];
    }

public:
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        prefix.assign(n, 0);
        
        // Step 1: Calculate prefix sums
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        
        // Initialize DP array with 1e9 (a value outside the possible score range)
        dp.assign(n, 1e18);
        
        // Alice must take at least 2 stones, starting at index 1
        return solve(1);
    }
};