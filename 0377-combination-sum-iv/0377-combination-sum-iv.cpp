class Solution {
public:

    int s(int target,vector<int> &dp,vector<int>& nums){
   
    if(target==0) { return 1;}
    if(target<0) return 0;
   
    if(dp[target]!=-1){
        return dp[target];
    }
     int ans=0;
    
    
    for(int i=0;i<nums.size();i++){ 
   ans = (ans + s(target - nums[i], dp,nums)) ;
    }
    return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return s(target,dp,nums);
    }
};