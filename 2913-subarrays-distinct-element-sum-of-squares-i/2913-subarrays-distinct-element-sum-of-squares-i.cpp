class Solution {
public:
    int sumCounts(vector<int>& nums) {
     int ans=0;
      for(int i=0;i<nums.size();i++){
         vector<int> freq(101,0);
        int temp=0;
        
        for(int j=i;j<nums.size();j++){
            freq[nums[j]]++;
            if(freq[nums[j]]==1){
                temp++;
            }
            ans+=(temp*temp);
        }
        
      }  
      return ans;
    }
};