class Solution {
public:
     long long query(long long idx,vector<int>& bits){
        long long sum=0;
        while(idx>0){
            sum+=bits[idx];
            idx-= idx& (-idx);

        }
        return sum;
    }
    void update(long long idx,vector<int>& bits,long long size){
        while(idx<=size){
            bits[idx]++;
            idx+=idx& (-idx);
        }
    }
    int reversePairs(vector<int>& nums) {
        
         int n=nums.size();
         long long maxi=nums[0];
         int mini=nums[0];
         vector<long long> temp;
        for (int x : nums) {
    temp.push_back(x);
    temp.push_back(2LL * x);
}
        sort(temp.begin(),temp.end());
        map<long long,int> mp;
        int counter=1;
        for(int i=0;i<temp.size();i++){
            if(mp[temp[i]]!=0){
                continue;
            }
            mp[temp[i]]=counter;
            counter++;
        }
         for(int x:nums){
            maxi=max(maxi,(long long)x);
            mini=min(mini,x);
         }
        
        
        vector<int> bits(counter+1,0);
       int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            count += query(mp[nums[i]] - 1, bits);
            update(mp[2LL*nums[i]], bits, counter);
        }
        return count;
    }
};