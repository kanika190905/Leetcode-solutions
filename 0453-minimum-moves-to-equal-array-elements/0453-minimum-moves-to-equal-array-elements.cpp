class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            ans+=(nums[i]-nums[0]);
            int t=nums[i]-nums[0];
            for(int j=0;j<nums.size();j++){
                if(j==i) continue;
                nums[j]+=t;
            }
        }
        return ans;
    }
};