class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       unordered_set<int> mp;
       for(int x:nums){
        mp.insert(x);
       } 
    int n=1;
    int kk=k;
       while(true){
        if(mp.find(kk)==mp.end()){
            return kk;
        }
        n++;
        kk=k*n;
       }

    }
};