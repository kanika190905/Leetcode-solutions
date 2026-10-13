class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.rbegin(),nums.rend());
        long long ans=0;
        if(nums.size()%2==0){
            for(int j=0;j<nums.size()/2;j++)
            ans+=(nums[j]*nums[j]);
            for(int j=nums.size()/2;j<nums.size();j++)
            ans-=(nums[j]*nums[j]);
        }
        else {
            for(int j=0;j<=nums.size()/2;j++)
            ans+=(nums[j]*nums[j]);
            for(int j=(nums.size()/2)+1;j<nums.size();j++)
            ans-=(nums[j]*nums[j]);
        }
    return ans;
    }
};