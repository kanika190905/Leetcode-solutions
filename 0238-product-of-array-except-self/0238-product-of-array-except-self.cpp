class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1,p2=1;
        bool flag1=false,flag2=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && flag1){
                flag2=true;
            }
            if(nums[i]==0 && !flag1){
                flag1=true;
            }
            if(flag1){
                if(nums[i]==0)
                p2*=product;
                if(nums[i]!=0){
                    p2*=nums[i];
                }
            }
            product*=nums[i];
        }
        vector<int> ans;
        for(int x:nums){
            if(x!=0)
            ans.push_back(product/x);
            else{
                if(flag2){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(p2);
                }
            }
        }
        return ans;
    }
};