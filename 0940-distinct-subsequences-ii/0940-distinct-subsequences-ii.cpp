class Solution {
public:
    const int MOD=1e9+7;
    int solve(int i,vector<int>& dp,string& s){
        
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        vector<bool> seen(26,false);
        for(int j=i+1;j<s.size();j++){
            if(!seen[s[j]-'a']){
                seen[s[j]-'a']=true;
                ans=(ans+solve(j,dp,s))%MOD;
            }
        }
        return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
        vector<int> dp(s.size()+1,-1);
        int total=0;
        vector<bool> visited(26,0);
        for(int i=0;i<s.size();i++){
            if(!visited[s[i]-'a']){
                visited[s[i]-'a']=true;
                total=(total+solve(i,dp,s))%MOD;
            }
        }
        return total;
    }
};