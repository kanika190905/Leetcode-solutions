class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=INT_MIN,ans;
         for(int i=0;i<nums.size();i++){
                h=max(h,nums[i]);
            }
        
        while(l<=h){
            int mid=l+(h-l)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=(int)ceil((double)nums[i]/mid);
            }
            if( sum<=threshold){
                
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};