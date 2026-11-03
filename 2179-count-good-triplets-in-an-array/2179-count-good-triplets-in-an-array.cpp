class Solution {
public:
    long long query(int idx, vector<int>& bit) {
        long long sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    void update(int idx, int delta, vector<int>& bit, int n) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int offset=1;
       int n = nums1.size();
        map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums2[i]]=i;
        }
        vector<int> temp(nums1.size());
        vector<int> left(n+1,0);
        for(int i=0;i<nums1.size();i++){
            temp[i]=mp[nums1[i]];
        }
        int nn=nums1.size();
        
        long long ans=0;
        vector<int> right(n+1,0);

        for (int x:temp)
            update(x+1,1,right,n);

        for (int x:temp) {
            update(x+1,-1,right,n);
            long long leftSmaller =query(x,left);
            

            
            long long rightGreater =query(n,right)-query(x+1,right);

            ans += leftSmaller*rightGreater;

            update(x+1, 1, left, n);
        }

        return ans; 
    }
};