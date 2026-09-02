class Solution {
public:
    int solve(int idx,int count,bool tight,vector<vector<vector<int>>> &dp,string &s){
        if(idx==s.size()){
            return count;
        }
        if(dp[idx][tight][count]!=-1) return dp[idx][tight][count];
        int ans=0;
        int limit=tight?s[idx]-'0':9;
      
       for(int d=0;d<=limit;d++){
          
          
            bool newTight=tight&&(d==limit);
          
            if(d == 1) {
                ans += solve(idx + 1, count + 1, newTight, dp, s);
            } else {
                ans += solve(idx + 1, count, newTight, dp, s);
            }
        }
        return dp[idx][tight][count]=ans;
    }
    int countDigitOne(int n) {
         string s=to_string(n);
        vector<vector<vector<int>>> dp(s.size(), vector<vector<int>>(2, vector<int>(s.size() + 1, -1)));
       
        return solve(0,0,true,dp,s);
    }
};