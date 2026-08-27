class NumArray {
public:
    int n;
    vector<int> bit;
    vector<int> nums;

    int query(int idx) {
        int sum = 0;

        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        bit.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int idx = i + 1;

            while (idx <= n) {
                bit[idx] += nums[i];
                idx += idx & (-idx);
            }
        }
    }

    void update(int index, int val) {

        int delta = val - nums[index];
        nums[index] = val;

        index++;  // 0-based → 1-based

        while (index <= n) {
            bit[index] += delta;
            index += index & (-index);
        }
    }

    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};