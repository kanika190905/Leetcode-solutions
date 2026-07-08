class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> PS(n), PX(n), PC(n);

        // Powers of 10 modulo MOD
        vector<long long> power(n + 1, 1);
        for (int i = 1; i <= n; i++)
            power[i] = (power[i - 1] * 10) % MOD;

        // Build PS, PX and PC
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            // Prefix Sum
            PS[i] = d + (i ? PS[i - 1] : 0);

            if (d == 0) {
                PX[i] = (i ? PX[i - 1] : 0);
                PC[i] = (i ? PC[i - 1] : 0);
            } else {
                PX[i] = (((i ? PX[i - 1] : 0) * 10LL) + d) % MOD;
                PC[i] = (i ? PC[i - 1] : 0) + 1;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            // Sum of digits
            long long sum = PS[r] - (l ? PS[l - 1] : 0);

            // Count of non-zero digits
            long long cnt = PC[r] - (l ? PC[l - 1] : 0);

            if (cnt == 0) {
                ans.push_back(0);
                continue;
            }

            long long left = (l ? PX[l - 1] : 0);

            long long x =
                (PX[r] - (left * power[cnt]) % MOD + MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};