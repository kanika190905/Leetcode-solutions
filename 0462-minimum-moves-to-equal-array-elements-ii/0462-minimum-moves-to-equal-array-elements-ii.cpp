class Solution {
public:
    int minMoves2(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int n=nums.size();
      int ans=0;
      for(int x:nums){
        ans+=abs(x-nums[n/2]);
      }  
    int ans2=0;
    if(n%2==0){
    for(int x:nums){
        ans2+=abs(x-nums[(n/2)-1]);
      } }
      if(n%2==0) return min(ans,ans2);
      return ans;
    }
};