class Solution {
public:
    bool helper(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=j;k>=0;k--){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=helper(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j]=helper(i,j-1,s,p,dp)||helper(i-1,j,s,p,dp); //empty,one char
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,s,p,dp);
    }
};