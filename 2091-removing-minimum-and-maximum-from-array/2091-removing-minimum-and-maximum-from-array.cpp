class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int minii=0;
        int maxii=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxii=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minii=i;
            }
        }
        int n=nums.size();
        int ans=0;
        int left=0;
        int right=0;
        int lr=0;
        left=max(maxii+1,minii+1);
        right=max(n-maxii,n-minii);
        lr=min(maxii+1,minii+1)+n-max(maxii,minii);
        return min({left,right,lr});
        
    }
};