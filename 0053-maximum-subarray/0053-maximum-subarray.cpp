class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            //extend the given subarray or start a new subarray
            current_sum=max(current_sum+nums[i],nums[i]);
            maxi=max(maxi,current_sum);
        }
        return maxi;
    }
};