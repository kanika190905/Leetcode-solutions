class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
       while(true){
        if (is_sorted(nums.begin(), nums.end())) return cnt;
        int i1=-1,i2=-1;
        int mini=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1]<mini){
                mini=nums[i]+nums[i+1];
                i1=i;
                i2=i+1;
            }
        }
        if(i1!=-1){
            cnt++;
            nums[i1]=mini;
            for(int j=i1+1;j<nums.size()-1;j++){
                nums[j]=nums[j+1];
            }
            nums.pop_back();
        }
       } 
       return 0;
    }
    
};