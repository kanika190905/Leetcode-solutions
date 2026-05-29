class Solution {
public:
    int helper(int n){
        int sum=0;
        while(n>0){
            int r=n%10;
            sum+=r;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int x=helper(nums[i]);
            nums[i]=x;
            mini=min(mini,x);
        }
        return mini;
    }
};