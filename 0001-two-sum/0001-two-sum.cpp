class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> withIdx;
        for(int i=0;i<nums.size();i++){
            withIdx.push_back({nums[i],i});
        }
        int i=0,j=nums.size()-1;
        sort(withIdx.begin(),withIdx.end());
        while(i<j){
            if(withIdx[i].first+withIdx[j].first==target){
                return{withIdx[i].second,withIdx[j].second};
            }
            else if(withIdx[i].first+withIdx[j].first>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {-1};
    }
};