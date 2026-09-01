class Solution {
public:
    int solve(int idx,bool tight,bool one,vector<vector<vector<int>>> &dp,int n,int length){
        if(idx==length){
            return 1;
        }
        if (dp[idx][tight][one] != -1)
            return dp[idx][tight][one];

        int ans=0;
        int limit = tight ? ((n >> (length - idx - 1)) & 1) : 1;
        if(one){
            ans+=solve(idx+1,tight && (0==limit),false,dp,n,length);
        }
        else{
            ans+=solve(idx+1,tight && (0==limit),false,dp,n,length);
            if(limit>=1)
            ans+=solve(idx+1,tight&& (limit==1),true,dp,n,length);
        }
        return dp[idx][tight][one]=ans;
    }
    int findIntegers(int n) {
        int length = 32 - __builtin_clz(n);
        vector<vector<vector<int>>> dp(
            length,
            vector<vector<int>>(2,
                vector<int>(2, -1)
            )
        );

        return solve(0,true,false,dp,n,length);

    }
};