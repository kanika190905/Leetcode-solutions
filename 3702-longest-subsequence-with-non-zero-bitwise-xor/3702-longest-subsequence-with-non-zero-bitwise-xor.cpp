class Solution {
public:

    int longestSubsequence(vector<int>& nums) {
       int maxi=nums[0];
       int cnt=0;
       if(nums[0]==0) cnt++;
       for(int i=1;i<nums.size();i++){
        maxi^=nums[i];
        if(nums[i]==0) cnt++;
       } 
       if(maxi!=0) return nums.size();
        if(cnt==nums.size()) return 0;
        return nums.size()-1;
    }
};