class Solution {
public:
    long long solve(int idx,bool tight,int limit,string &s,string &suffix,vector<vector<long long>> &dp){
        if (suffix.size() > s.size())
    return 0;
        int prefixLen = s.size() - suffix.size();

        if (idx == prefixLen) {
            if (tight) {
                string last = s.substr(prefixLen);
                return suffix <= last;
            }
            return 1;
        }
        if(dp[idx][tight]!=-1) return dp[idx][tight];
        int limitt=tight?s[idx]-'0':9;
        long long ans=0;
        for(int d=0;d<=limit;d++){
            if(d>limitt) break;
            int newTight=tight&&(d==limitt);
            ans+=solve(idx+1,newTight,limit,s,suffix,dp);
        }
        return dp[idx][tight]=ans;
        
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        
        start-=1;
        string s1=to_string(start);
        string s2=to_string(finish);
        vector<vector<long long>> dp(s2.size()+5,vector<long long>(2,-1));
        vector<vector<long long>> dp2(s1.size()+5,vector<long long>(2,-1));
        return solve(0,true,limit,s2,s,dp)-solve(0,true,limit,s1,s,dp2);
    }
};