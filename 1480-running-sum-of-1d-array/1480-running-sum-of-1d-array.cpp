class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> b(n);
        int sum=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            b[i]=sum;
            sum+=nums[i+1];
        }
        b[n-1]=sum;
        return b;
    }
};