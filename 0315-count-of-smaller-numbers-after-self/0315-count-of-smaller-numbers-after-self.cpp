class Solution {
public:
    int query(int idx,vector<int>& bits){
        int sum=0;
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
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        int offset=10001;
        int size=20002;
        vector<int> bits(size+1,0);
        vector<int> count(n,0);
        for(int i=n-1;i>=0;i--){
            int newVal=nums[i]+offset;
            count[i]=query(newVal-1,bits);
            update(newVal,bits,size);
        }
        return count;
    }
};