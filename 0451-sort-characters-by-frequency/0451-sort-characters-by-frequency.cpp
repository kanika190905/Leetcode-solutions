class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second; // sort by frequency (descending)
    }

    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // count frequency
        for (char c : s) freq[c]++;

        // move to vector for sorting
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), cmp);

        // build result string
        string ans = "";
        for (auto& p : vec) {
            ans.append(p.second, p.first); // repeat char freq times
        }

        return ans;
    }
};