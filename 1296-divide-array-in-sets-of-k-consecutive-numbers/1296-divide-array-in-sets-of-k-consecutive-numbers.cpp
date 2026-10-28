class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        
        for(auto it:mp){
            while (mp[it.first] > 0) {
            for(int i=0;i<k;i++){
                if(mp[it.first+i]<=0){
                    return false;
                }
                mp[it.first+i]--;
            }}
        }
        return true;
    }
};