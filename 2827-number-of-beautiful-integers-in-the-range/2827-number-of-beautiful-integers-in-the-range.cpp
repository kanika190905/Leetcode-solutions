class Solution {
public:
    int solve(int idx,bool tight,bool lead_zero,int evenCount,int rem,int k,string &s,vector<vector<vector<vector<vector<int>>>>> &dp){
        if(idx==s.size()){
            if((evenCount==10) && (rem==0)){
                return 1;
            }
            return 0;
        }
        if(dp[idx][tight][lead_zero][evenCount][rem]!=-1) return dp[idx][tight][lead_zero][evenCount][rem];
        int ans=0;
        int limit=tight?s[idx]-'0':9;
        for(int d=0;d<=limit;d++){
            bool newTight=tight&&(d==limit);
            bool new_zero=lead_zero&&(d==0);
            int even_new=evenCount;
            if(!new_zero){if(d%2==0){ even_new+=1;}else even_new-=1;}
            int new_r=(((rem*10)+d)%k);
            ans+=solve(idx+1,newTight,new_zero,even_new,new_r,k,s,dp);
        }
        return dp[idx][tight][lead_zero][evenCount][rem]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        low-=1;
       string s1=to_string(low);
       string s2=to_string(high);
       vector<vector<vector<vector<vector<int>>>>> dp(11,vector<vector<vector<vector<int>>>>(2,vector<vector<vector<int>>>(2,vector<vector<int>>(21,vector<int>(25,-1)))));
       
        vector<vector<vector<vector<vector<int>>>>> dp2(11,vector<vector<vector<vector<int>>>>(2,vector<vector<vector<int>>>(2,vector<vector<int>>(21,vector<int>(25,-1)))));
       
       return solve(0,true,true,10,0,k,s2,dp)-solve(0,true,true,10,0,k,s1,dp2);
    }
};