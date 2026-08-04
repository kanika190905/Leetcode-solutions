class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int mini=INT_MAX,maxi=INT_MIN;
       bool present[101] = {};
       for(int x:nums){
        present[x] = true;
        maxi=max(maxi,x);
        mini=min(mini,x);
       } 
       vector<int> ans;
       for(int i=mini+1;i<maxi;i++){
        if(!present[i])
        ans.push_back(i);
       }
       if(maxi-mini==0) return {};
       return ans;
    }
};