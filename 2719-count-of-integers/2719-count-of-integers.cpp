class Solution {
public:
    const int MOD=1e9+7;
    void decrement(string &s){
        int n=s.size()-1;
        while(n>=0){
        if(s[n]>='1' && s[n]<='9' ){
            s[n]=s[n]-1;
            return;
        }
        
        s[n]='9';
        n--;
        }

    }
    int solve(int idx,int tight,int sum,string &s,int mini,int maxi,vector<vector<vector<int>>> &dp){
        if(sum>maxi) return 0;
        if(idx==s.length()){
            if(sum>=mini && sum<=maxi){
                return 1;
            }
            return 0;
        }
        if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];
        int limit=tight?s[idx]-'0':9;
        int ans=0;
        for(int d=0;d<=limit;d++){
            int newTight=tight&&(d==limit);
            int newSum=sum+d;
            ans=(ans+solve(idx+1,newTight,newSum,s,mini,maxi,dp))%MOD;
        }
        return dp[idx][tight][sum]=ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        vector<vector<vector<int>>> dp(23,vector<vector<int>>(2,vector<int>(max_sum+1,-1)));
         vector<vector<vector<int>>> dp2(23,vector<vector<int>>(2,vector<int>(max_sum+1,-1)));
         decrement(num1);
         int max1=solve(0,true,0,num1,min_sum,max_sum,dp);
         int max2=solve(0,true,0,num2,min_sum,max_sum,dp2);

         return (max2-max1+MOD)%MOD;
    }
};