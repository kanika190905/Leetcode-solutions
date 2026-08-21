class Solution {
public:
    int helper(int i,vector<int>& days, vector<int>& costs, vector<int>& dp){
        if(i==days.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int take1=1e9;

          take1=costs[0]+helper(i+1,days,costs,dp);
        int take7=1e9;
        int take30=1e9;
            int idx1=upper_bound(days.begin(),days.end(),days[i]+6)-days.begin();
            if(idx1)
           take7=costs[1]+helper(idx1,days,costs,dp);
       int idx2=upper_bound(days.begin(),days.end(),days[i]+29)-days.begin();
            if(idx2)
           take30=costs[2]+helper(idx2,days,costs,dp);
        return dp[i]=min({take1,take7,take30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return helper(0,days,costs,dp);
    }
};