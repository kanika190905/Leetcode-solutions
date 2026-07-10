class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char ch : t)
            freq[ch]++;

        int left = 0;
        int count = t.size();

        int start = 0;
        int minLen = INT_MAX;

        for (int i = 0; i < s.size(); i++) {

            if (freq[s[i]] > 0)
                count--;

            freq[s[i]]--;

            while (count == 0) {

                if (i - left + 1 < minLen) {
                    minLen = i - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};