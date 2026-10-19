class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
       vector<int> ans;
       int cnt=0,cnt2=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<target){
            cnt++;
        }
        else if(nums[i]==target){
            cnt2++;
        }
       
       } 
       for(int i=cnt;i<cnt2+cnt;i++){
        ans.push_back(i);
       }
       return ans;
    }
};