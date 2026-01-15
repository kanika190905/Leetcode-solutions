class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int el;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                el=nums[i];
                count++;
            }
            else if(el==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        
        return el;
    }
};