class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k<0) return 0;
        int l=0,r=0,cnt=0,sub=0;
        unordered_map<int,int> m;
        while(r<nums.size()){
            m[nums[r]]++;
            if(m[nums[r]]==1){
                cnt++;
            }
            while(cnt>k){
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    cnt--;
                }
                l++;
            }
            
            sub+=(r-l+1);
            r++;
        }
        return sub;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};