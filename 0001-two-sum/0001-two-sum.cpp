class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<int> ans;
        vector<pair<int,int>> withIdx;
        for(int i=0;i<=r;i++){
            withIdx.push_back({nums[i],i});
        }
        sort(withIdx.begin(),withIdx.end());
        while(l<r){
            if(withIdx[l].first+withIdx[r].first==target){
                ans.push_back(withIdx[l].second);
                ans.push_back(withIdx[r].second);
                break;
            }
            else if(withIdx[l].first+withIdx[r].first<target){
                l++;
            }
            else r--;
        }
        return ans;
    }
};