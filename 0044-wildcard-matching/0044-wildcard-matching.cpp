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
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
        dp[0][0]=true;
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*') dp[0][j]=dp[0][j-1];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                      dp[i][j]=dp[i][j-1]||dp[i-1][j]; //empty,one char
                    }
              else  dp[i][j]=false;   
            }
        }
        return dp[m][n];
    }
};