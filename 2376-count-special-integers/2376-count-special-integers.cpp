class Solution {
public:
    int solve(int idx,bool tight,int mask,bool is_good,vector<vector<vector<vector<int>>>> &dp,string &s,bool zero){
        if(idx==s.size()){
           if(is_good) return 1;
           return 0; 
        }
        if(dp[idx][tight][mask][is_good]!=-1) return dp[idx][tight][mask][is_good];
        int ans=0;
        int limit=tight?s[idx]-'0':9;
        for(int d=0;d<=limit;d++){
            
           int newmask=mask|(1<<d);
          if(d==0 && zero==true) newmask=mask;
            bool newTight=tight&&(d==limit);
           bool new_good=is_good;
           if(zero==false && (mask & (1 << d)) ){
            new_good=false;
           }
           bool newzero=false;
            if(d==0 && zero==true) newzero=true;
            ans+=solve(idx+1,newTight,newmask,new_good,dp,s,newzero);
        }
        return dp[idx][tight][mask][is_good]=ans;
    }
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        int mask=0;
        vector<vector<vector<vector<int>>>> dp(
    11,
    vector<vector<vector<int>>>(
        2,
        vector<vector<int>>(
            1024,
            vector<int>(2, -1)
        )
    )
);
        return solve(0,true,mask,true,dp,s,true)-1;
    }
};