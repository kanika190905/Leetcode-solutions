
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int maxVal = INT_MAX, totalLcm = 1;
        for (int x : nums) {
            maxVal = min(maxVal, x);
            totalLcm = lcm(totalLcm, x);
        }
        long long maxP = 1LL * totalLcm * maxVal;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
                if(prod>maxP){
                    break;
                }
            }
        }

        return ans;
    }
};
