class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;

    while (low <= high) {
        int mid = (high-low) / 2 +low;
        long long sq = 1LL * mid * mid;

        if (sq == num) return true;
        else if (sq < num) low = mid + 1;
        else high = mid - 1;
    }
    return false;
    }
};