class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
         vector<int> hash(nums.size());
        int maxi=1,last_idx=0;
        for(int idx=0;idx<nums.size();idx++){
            hash[idx]=idx;
            for(int prev_idx=0;prev_idx<idx;prev_idx++){
                if(nums[prev_idx]<nums[idx] && dp[idx]<dp[prev_idx]+1){
                dp[idx]=dp[prev_idx]+1;
                hash[idx]=prev_idx;
                }
            }
            if(dp[idx]>maxi){
            maxi=max(maxi,dp[idx]);
            last_idx=idx;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last_idx]);
        while(hash[last_idx]!=last_idx){
            last_idx=hash[last_idx];
            ans.push_back(nums[last_idx]);
        }
        reverse(ans.begin(),ans.end());
        for(int x:ans){
            cout<<x<<" ";
        }
        return maxi;
    }
};