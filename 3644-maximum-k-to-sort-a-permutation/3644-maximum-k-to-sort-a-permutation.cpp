class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=-1,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=i)
            ans=ans&nums[i];
        }
        if(ans!=-1)
        return ans;
        return 0;
    }
};