class Solution {
public:
    void helper(vector<int> &nums,int idx,vector<int> &temp,vector<vector<int>> &result){
        if(idx==nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        //take
        helper(nums,idx+1,temp,result);
        //backtrack
        temp.pop_back();
        //not take
        helper(nums,idx+1,temp,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        helper(nums,0,temp,result);
        return result;
    }
};