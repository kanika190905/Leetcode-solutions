class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0,r=0,cnt=0,cntOdd=0;
        while(r<nums.size()){
            if(nums[r]%2==1){
                cntOdd++;
            }
            while(cntOdd>k){
                cntOdd-=(nums[l]%2==1?1:0);
                l++;
            }
            int s=l;
            if(cntOdd==k) {
               while(nums[s]%2==0){
                cnt++;
                s++;
               }
               cnt++;
                }
            r++;
        }
        return cnt;
    }
};