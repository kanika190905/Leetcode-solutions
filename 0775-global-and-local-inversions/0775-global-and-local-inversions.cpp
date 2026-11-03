class Solution {
public:
    long long query(int idx,vector<int>& bits){
        long long sum=0;
        while(idx>0){
            sum+=bits[idx];
            idx-= idx& (-idx);

        }
        return sum;
    }
    void update(int idx,vector<int>& bits,int size){
        while(idx<=size){
            bits[idx]++;
            idx+=idx& (-idx);
        }
    }
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        int size=100001;
        vector<int> bits(size+1,0);
        long long inv=0;
        for(int i=0;i<nums.size();i++){
            int newVal=nums[i];
            inv+=(query(size,bits)-query(newVal,bits));
            update(newVal+1,bits,size);
        }
        long long cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                cnt++;
            }
        }
        
        return cnt==inv;
    }
};