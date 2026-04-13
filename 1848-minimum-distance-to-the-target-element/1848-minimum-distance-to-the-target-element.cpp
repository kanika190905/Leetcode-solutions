class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
       int i=start-1,j=start+1,cnt=0;
       if(nums[start]==target) return 0;
       while(i>=0 && j<nums.size()){
        if(nums[i]==target || nums[j]==target){
            cnt++;
            return cnt;
        }
        i--;j++;
        cnt++;
       } 
       while(i>=0 ){
        if(nums[i]==target ){
            cnt++;
            return cnt;
        }
        i--;
        cnt++;
       }  
        while( j<nums.size() ){
        if(nums[j]==target ){
            cnt++;
            return cnt;
        }
        j++;
        cnt++;
       }  
      return 0; 
    }
};