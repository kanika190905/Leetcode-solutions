class Solution {
public:
    int solve(int idx,bool tight,bool zero,vector<vector<vector<int>>> &dp,string &s,vector<string> &digits){
        if(idx==s.size()){
            return 1;
        }
        if(dp[idx][tight][zero]!=-1) return dp[idx][tight][zero];
        int ans=0;
        int limit=tight?s[idx]-'0':9;
        if(zero){
          ans+=solve(idx+1,false,true,dp,s,digits);  
        }
       for(int i=0;i<digits.size();i++){
           int d=stoi(digits[i]);
           if(d>limit) continue; 
          
            bool newTight=tight&&(d==limit);
          
          
            ans+=solve(idx+1,newTight,false,dp,s,digits);
        }
        return dp[idx][tight][zero]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<vector<vector<int>>> dp(12,vector<vector<int>>(2,vector<int>(2,-1)));
        string s=to_string(n);
        return solve(0,true,true,dp,s,digits)-1;
    }
};