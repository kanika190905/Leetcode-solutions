class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2) return 0;
        int diff=nums[1]-nums[0];
        int cnt=1;
        int i=0,j=1,ans=0,maxi=INT_MIN;
        while( j<nums.size() && i<j){
            if(diff==(nums[j]-nums[j-1])){
                j++;
                cnt++;
                maxi=max(maxi,j-i);
            }
            else if(cnt>=3){
                ans+=(((maxi-1)*(maxi-2))/2);
                maxi=INT_MIN;
                diff=nums[j]-nums[j-1];
                cnt=1;
                i=j-1;

            }
            else{
                maxi=INT_MIN;
                diff=nums[j] - nums[j-1];
                cnt=1;
                i=j-1;
            }
        }
        if(maxi!=INT_MIN)
        ans+=(((maxi-1)*(maxi-2))/2);
        return ans;
    }
};