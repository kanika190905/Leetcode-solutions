class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> count(26, 0);

        // Count characters in s
        for (char c : s) {
            count[c - 'a']++;
        }

        // Remove characters using t
        for (char c : t) {
            count[c - 'a']--;
        }

        // Check if all are zero
        for (int x : count) {
            if (x != 0)
                return false;
        }

        return true;
    }
};
