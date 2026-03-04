class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i1=text1.size();
        int i2=text2.size();
        vector<vector<int>> dp(i1+1,vector<int>(i2+1,-1));
        for(int i=0;i<=i2;i++) dp[0][i]=0;
        for(int i=0;i<=i1;i++) dp[i][0]=0;
        for(int i=1;i<=i1;i++){
             for(int j=1;j<=i2;j++){
                if(text1[i-1]==text2[j-1]){
             dp[i][j]=1+dp[i-1][j-1];
        }
        else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             }
        }
        return dp[i1][i2];
    }
};