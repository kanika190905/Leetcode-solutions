class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int> m;
       vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(m[nums1[i]]==0){
                m[nums1[i]]=1;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(m[nums2[i]]==1){
                ans.push_back(nums2[i]);
                m[nums2[i]]=0;
            }
        }
        return ans;
    }
};