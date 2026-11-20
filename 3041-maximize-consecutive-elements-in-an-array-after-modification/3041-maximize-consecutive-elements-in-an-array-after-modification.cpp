class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int maxi=1;
        map<int,int> dp;
        sort(nums.begin(),nums.end());
        for(int x:nums){
            dp[x+1]=dp[x]+1;
            dp[x]=dp[x-1]+1;
            maxi=max({maxi,dp[x],dp[x+1]});
        }
        return maxi;
    }
};