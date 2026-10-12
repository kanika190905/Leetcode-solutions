class Solution {
public:
    const int MOD=1e9+7;
    int maxSum(vector<int>& nums, int k) {
       vector<int> v(32,0);
       for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)){
                    v[j]++;
                }
            }
       } 
       long long ans=0;
       while(k){
        long long temp=0;
       for(int i=0;i<32;i++){
        if(v[i]>=1){
            v[i]--;
            temp|=(1<<i);
        }
       }
       ans=(MOD+ans+(temp*temp))%MOD;
       k--;
       }
       return (int)ans;
    }
};