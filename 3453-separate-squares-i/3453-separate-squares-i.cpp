class Solution {
public:
    double separateSquares(vector<vector<int>>& s) {
        double lo = 1e18, hi = -1e18;
        for (auto &x : s) {
            lo = min(lo, (double)x[1]);
            hi = max(hi, (double)x[1] + x[2]);
        }

        double total = 0;
        for (auto &x : s) total += (double)x[2] * x[2];

        for (int i = 0; i < 80; i++) {
            double mid = (lo + hi) / 2, area = 0;

            for (auto &x : s) {
                double b = x[1], l = x[2];
                double h = min(l, max(0.0, mid - b));
                area += h * l;
            }

            if (area * 2 < total) lo = mid;
            else hi = mid;
        }

        return (lo + hi) / 2;
    }
};
