class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       int maxi=INT_MIN;
       int l=0,r=0;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
        while(mp[nums[i]]>k){
            mp[nums[l]]--;
            l++;
        }
        maxi=max(maxi,r-l+1);
        r++;
       } 
       return maxi;
    }
};