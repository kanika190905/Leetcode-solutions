class Solution {
public:
    int query(int idx, vector<int>& bit) {
        int sum = 0;
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

    int numTeams(vector<int>& rating) {
        int n = 100001;

        vector<int> left(n+1,0);
        vector<int> right(n+1,0);

        for (int x:rating)
            update(x,1,right,n);

        int ans=0;

        for (int x:rating) {
            update(x,-1,right,n);

            int leftSmaller =query(x-1,left);
            int leftGreater =query(n,left)-query(x,left);

            int rightSmaller =query(x-1, right);
            int rightGreater =query(n,right)-query(x,right);

            ans += leftSmaller*rightGreater
                 + leftGreater*rightSmaller;

            update(x, 1, left, n);
        }

        return ans;
    }
};