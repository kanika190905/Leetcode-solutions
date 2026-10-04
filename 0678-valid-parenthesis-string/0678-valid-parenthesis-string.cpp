class Solution {
public:
    bool solve(int i,int open,string &s,vector<vector<int>> &dp){
        if(i==s.size()){
            if(open==0){
                return true;
            }
            return false;
        }
        if(dp[i][open]!=-1){
            return dp[i][open];
        }
        bool take=false,notTake=false;
        if((s[i]==')'|| s[i]=='*')&& open>0){
            take=solve(i+1,open-1,s,dp);
        }
        if(s[i]=='('|| s[i]=='*'){
            notTake=solve(i+1,open+1,s,dp);
        }
        bool emptyy=false;
        if(s[i]=='*'){
            emptyy=solve(i+1,open,s,dp);
        }
        return dp[i][open]={take||notTake||emptyy};
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return solve(0,0,s,dp);
    }
};