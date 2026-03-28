class Solution {
public:
    int helper(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(j<0) return i+1;     //delete operations
        if(i<0) return j+1;    //insert

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=0+helper(i-1,j-1,s1,s2,dp);

        int deletee=1+helper(i-1,j,s1,s2,dp);
        int insert=1+helper(i,j-1,s1,s2,dp);
        int replace=1+helper(i-1,j-1,s1,s2,dp);

        return dp[i][j]=min(deletee,min(insert,replace)); 
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return helper(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};