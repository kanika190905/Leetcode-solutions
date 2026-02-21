class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> temp(nums.size());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]-1]++;
        }
        for(int i=0;i<nums.size();i++){
            if(temp[i]==0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};