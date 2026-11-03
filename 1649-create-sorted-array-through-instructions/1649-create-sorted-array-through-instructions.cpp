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
    int createSortedArray(vector<int>& instructions) {
        vector<int> nums=instructions;
        const int MOD=1e9+7;
        int n=nums.size();
        int size=100000;
        vector<int> bits(size+1,0);
        long long count=0;
        for(int i=0;i<n;i++){
            int newVal=nums[i];
            long long x=query(newVal-1,bits);
            long long y=query(size,bits)-query(newVal,bits);
            long long z=min(x,y);
            count=(count+z)%MOD;
            update(newVal,bits,size);
        }
        return count;
    }
};