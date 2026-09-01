class Solution {
public:
    int solve(int idx,bool tight,bool is_good,vector<vector<vector<int>>> &dp,string &s){
        if(idx==s.size()){
            if(is_good==1) return 1;
            return 0;
        }
        if(dp[idx][tight][is_good]!=-1) return dp[idx][tight][is_good];
        int ans=0;
        int limit=tight?s[idx]-'0':9;
        for(int d=0;d<=limit;d++){
            if(d==3||d==7||d==4) continue;
            bool newTight=tight&&(d==limit);
           bool new_good=is_good;
            if(d==2||d==5||d==6||d==9)
             new_good=true;
            ans+=solve(idx+1,newTight,new_good,dp,s);
        }
        return dp[idx][tight][is_good]=ans;
    }
    int rotatedDigits(int n) {
        string s=to_string(n);
        vector<vector<vector<int>>> dp(6,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,1,0,dp,s);
    }
};