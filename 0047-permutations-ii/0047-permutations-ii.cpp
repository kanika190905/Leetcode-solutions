class Solution {
public:
    
    void solve(vector<int>& nums, vector<bool>& visited,
               vector<int>& temp, vector<vector<int>>& ans) {
        
        // Base case
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            
            // If already used → skip
            if (visited[i]) continue;
            
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
            
            // Choose
            visited[i] = true;
            temp.push_back(nums[i]);
            
            // Recurse
            solve(nums, visited, temp, ans);
            
            // Backtrack
            temp.pop_back();
            visited[i] = false;
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        
        solve(nums, visited, temp, ans);
        
        return ans;
    }
};
