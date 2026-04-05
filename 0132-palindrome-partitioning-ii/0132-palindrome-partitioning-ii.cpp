class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int f(int i, string& s, vector<int>& dp){
        if(i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;

        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                int cost = 1 + f(j+1, s, dp);
                mini = min(mini, cost);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        vector<int> dp(s.size(), -1); // FIXED
        return f(0, s, dp) - 1;
    }
};