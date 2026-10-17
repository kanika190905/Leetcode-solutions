
class Solution {
public:
    int digit_sum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<pair<int, int>, int>> temp;

        for (int i = 0; i < n; i++) {
            temp.push_back({
                {digit_sum(nums[i]), nums[i]}, i
            });
        }

        sort(temp.begin(), temp.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || temp[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = temp[j].second;
                cycle_size++;
            }

            if (cycle_size > 0)
                swaps += cycle_size - 1;
        }

        return swaps;
    }
};
