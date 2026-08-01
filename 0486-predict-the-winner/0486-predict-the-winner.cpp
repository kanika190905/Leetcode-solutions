class Solution {
public:
    int helper(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(i == j) return nums[i];
        int take1=nums[i]+min(helper(i+1,j-1,nums),helper(i+2,j,nums));
        int takel=nums[j]+min(helper(i+1,j-1,nums),helper(i,j-2,nums));
        return max(take1,takel);
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int sum=0;
       for(int x:nums){
        sum+=x;
       } 
      int ans=helper(0,nums.size()-1,nums);
       if((ans)>=(sum-ans)) return true;
       return false;
    }
};