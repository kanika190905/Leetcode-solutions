class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=nums[n-1],mini=nums[0],smaxi=nums[n-2],smini=nums[1],tmaxi=nums[n-3],ans=nums[2];
        
        if(nums.size()==3){
            return 0;
        }
        return min({maxi-ans,smaxi-smini,tmaxi-mini});
    }
};