class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int cnt=0;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0){
            int n=nums[i]%10;
            
            temp.push_back(n);
            cnt++;
            nums[i]/=10;}
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                ans.push_back(temp[i]);
            }
            int m=temp.size();
             for(int i=0;i<m;i++){
                temp.pop_back();
            }
        }
        return ans;
    }
};