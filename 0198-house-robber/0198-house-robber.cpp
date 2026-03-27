class Solution {
public:
  
    int rob(vector<int>& nums) {
        int curr=nums[0],prev=0,curr2;
       
        for(int i=1;i<nums.size();i++){
            
            int take=nums[i];
            if(i>1) take+=prev;

            int notTake=curr;

            curr2=max(take,notTake);
            prev=curr;
            curr=curr2;
        }
        return curr;
    }
};