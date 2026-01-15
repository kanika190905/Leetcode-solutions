class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int segment=0;
        int currSeg=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currSeg++;
            }
            else 
                currSeg=0;
            segment=max(segment,currSeg);
        }
        return segment;
    }
};