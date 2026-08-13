class Solution {
public:
    int solve(int i,vector<int>& nums, int target,vector<vector<int>>& dp,int n){
        if(target > n || target < -n) return 0;
        if(i==nums.size() && target==0){
            return 1;
        }
        else if(i==nums.size() ){
            return 0;
        }
        
        if(dp[i][target+n]!=1e9) return dp[i][target+n];
        int add=0;
        
         add=solve(i+1,nums,target-nums[i],dp,n);
        int sub=solve(i+1,nums,target+nums[i],dp,n);
       
        
        return dp[i][target+n]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       int sum=0;
        for(int x:nums) sum+=x;
        int n=nums.size();
        vector<vector<int>> dp(nums.size(),vector<int>((2*sum)+1,1e9));
        return solve(0,nums,target,dp,sum);
    }
};