class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; 
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                if (i != j)  // avoid self-swap
                    nums[i] = nums[j], nums[j] = 0;
                i++;
            }
        }
    }
};
