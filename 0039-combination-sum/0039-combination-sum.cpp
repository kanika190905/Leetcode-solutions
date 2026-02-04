class Solution {
public:
    void combine(int idx,int target,vector<int>& arr,vector<int>& temp,vector<vector<int>>& ans){
       if(idx==arr.size()){
        if(target==0){
            ans.push_back(temp);
        }
        return;
       } 
       if(arr[idx]<=target){
        temp.push_back(arr[idx]);
        combine(idx,target-arr[idx],arr,temp,ans);
        temp.pop_back();
       }
       combine(idx+1,target,arr,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combine(0,target,candidates,temp,ans);
        return ans;
    }
};