class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int x:nums){
            mp[x]++;
            maxi=max(maxi,x);
        }
         int l=0,r=nums.size()-1;
         vector<int> temp=nums;
         if(k==nums.size()) return maxi;
         sort(temp.rbegin(),temp.rend());
       if(k==1){
        int j=0;
        while(j<temp.size() && mp[temp[j]]!=1){
            j++;
        }
        if(j!=temp.size())
        return temp[j];
        else return -1;
       }
        if(l<r){
            if(mp[nums[l]]==1 && mp[nums[r]]==1){
                return max(nums[l],nums[r]);
            }
            else if(mp[nums[l]]==1){
                return nums[l];
            }
            else if(mp[nums[r]]==1){
                return nums[r];
            }
            
        }
        return -1;
    }
};