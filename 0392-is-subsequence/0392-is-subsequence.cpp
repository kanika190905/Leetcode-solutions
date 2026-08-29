class Solution {
public:
    bool solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(i==s.size()) return 1;
        if(j==t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        bool take=0;
        if(s[i]==t[j])
         take=solve(i+1,j+1,s,t,dp);
        bool notTake=solve(i,j+1,s,t,dp);
        return dp[i][j]=take||notTake;
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(0,0,s,t,dp);
    }
};