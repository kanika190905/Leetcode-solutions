class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        vector<bool> prev((sum/2) + 1, false);
        vector<bool> curr((sum/2) + 1, false);

        prev[0] = true;
         curr[0] = true; 
        if(nums[0] <= (sum/2))
            prev[nums[0]] = true;
        for(int ind=1;ind<nums.size();ind++){
            for(int target=1;target<=sum/2;target++){
                bool notTake=prev[target];
                bool take=false;
                if(nums[ind]<=target){
                take=prev[target-nums[ind]];
            }
            curr[target]=take|notTake;
            }
            prev=curr;
        }
        return prev[sum/2];
    }
};