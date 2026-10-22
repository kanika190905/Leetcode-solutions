class Solution {
public:
    int minOperations(vector<int>& nums) {
        int idx=-1,n=nums.size();
        bool flag1=false,flag2=false,flag=false;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag=true;
                break;
            }
        }
        if(!flag) return 0;
        flag=false;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]-nums[i]!=1){
                flag=true;
                break;
            }
        }
        if(!flag) return 1;
        for(int i=n-1;i>0;i--){
            if(nums[i]-nums[i-1]!=1 && !flag1){
                idx=min(i,n-i+2);
                flag1=true;
            }
            else if(nums[i]-nums[i-1]!=1 && flag1){
                flag2=true;
                break;
            }
        }
       
        flag1=false;
        bool flag22=false;
        int idx2=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]-nums[i+1]!=1 && !flag1){
                idx2 = min(n - i, i + 2);
                flag1=true;
            }
            else if(nums[i]-nums[i+1]!=1 && flag1){
                flag22=true;
                break;
            }
        }
        if(idx!=-1 && idx2!=-1 && !flag2 && !flag22){
            return min(idx,idx2);
        }
        else if(idx!=-1 && !flag2){
            return idx;
        }
        else if(idx2!=-1 && !flag22){
            return idx2;
        }
        return -1;
    }
};