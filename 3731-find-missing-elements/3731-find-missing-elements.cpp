class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int mini=INT_MAX,maxi=INT_MIN;
       unordered_map<int,int> mp;
       for(int x:nums){
        mp[x]++;
        maxi=max(maxi,x);
        mini=min(mini,x);
       } 
       vector<int> ans;
       for(int i=mini+1;i<maxi;i++){
        if(mp[i]==0)
        ans.push_back(i);
       }
       if(maxi-mini==0) return {};
       return ans;
    }
};