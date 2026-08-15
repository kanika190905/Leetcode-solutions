class Solution {
public:
    int solve(vector<tuple<int,int,int>>& jobs,int i,vector<int>& start, vector<int>& dp){
        if(i==jobs.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int notTake=solve(jobs,i+1,start,dp);
        int take=0;
        auto [p,s,e]=jobs[i];
        int idx=lower_bound(start.begin(),start.end(),e)-start.begin();
        take=p+solve(jobs,idx,start,dp);
        return dp[i]=max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       vector<tuple<int,int,int>> jobs(profit.size());
      for(int i=0;i<jobs.size();i++){
        jobs[i]={profit[i],startTime[i],endTime[i]};
      }
      sort(startTime.begin(),startTime.end());
      sort(jobs.begin(), jobs.end(), [](auto& a, auto& b) {
    return get<1>(a) < get<1>(b);
});
        vector<int> dp(startTime.size(),-1);
        return solve(jobs,0,startTime,dp);
    }
};