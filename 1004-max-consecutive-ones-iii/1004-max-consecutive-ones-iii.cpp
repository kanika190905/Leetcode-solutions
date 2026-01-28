class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0,l=0;
        int cnt=0,maxi=INT_MIN;
        while(r<nums.size()){
            if(nums[r]==0){
                cnt++;
            } 
            while(cnt>k){
                   if(nums[l]==0) cnt--;
                    l++;
                }      
            maxi=max(maxi,r-l+1);
            r++;
        }
        
        return maxi;
    }
};