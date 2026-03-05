class Solution {
public:
    int longestCommonSubsequence(vector<int>& nums1, vector<int>& nums2) {
        int i1=nums1.size();
        int i2=nums2.size();
        vector<vector<int>> dp(i1+1,vector<int>(i2+1,-1));
        int ans=0;
        for(int i=0;i<=i2;i++) dp[0][i]=0;
        for(int i=0;i<=i1;i++) dp[i][0]=0;

        for(int i=1;i<=i1;i++){
             for(int j=1;j<=i2;j++){
                if(nums1[i-1]==nums2[j-1]){
             dp[i][j]=1+dp[i-1][j-1];
             ans=max(ans,dp[i][j]);
        }
        else  dp[i][j]=0;
             }
        }
        
        return ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = longestCommonSubsequence(nums1,nums2);
        return ans;
    }
};