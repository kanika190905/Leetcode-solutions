class Solution {
public:
    
    void solve( vector<int>& freq,vector<int>& temp,vector<int>& nums, vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i =0; i < nums.size(); i++) {
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                solve(freq,temp,nums,ans);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(nums.size(),0);
        solve(freq,temp, nums, ans);
        
        return ans;
    }
};
