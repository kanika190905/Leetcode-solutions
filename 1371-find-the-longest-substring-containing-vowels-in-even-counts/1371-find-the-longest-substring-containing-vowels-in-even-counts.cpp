class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> first(32, -1);
        first[0] = 0; 

        int x = 0;
        int maxi = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') x ^= 1;
            else if(s[i] == 'e') x ^= 2;
            else if(s[i] == 'i') x ^= 4;
            else if(s[i] == 'o') x ^= 8;
            else if(s[i] == 'u') x ^= 16;
            if(first[x] != -1) {
                maxi = max(maxi, i + 1 - first[x]);
            } 
          
            else {
                first[x] = i + 1;
            }
        }

        return maxi;
    }
};