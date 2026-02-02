class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[i];
        }
        int j=0;
        for(int i=nums.size();i<2*nums.size();i++){
            ans[i]=nums[j];
            j++;
        }
        return ans;
    }
};