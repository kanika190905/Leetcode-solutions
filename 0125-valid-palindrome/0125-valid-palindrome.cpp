class Solution {
    bool valid(char c) {
        return ( (c >= 'a' && c <= 'z') || 
                 (c >= 'A' && c <= 'Z') || 
                 (c >= '0' && c <= '9') );
    }
    bool checkPalindrome(string a) {
        int s = 0;
        int e = a.length() - 1;

        while (s <= e) {
            if (tolower(a[s]) != tolower(a[e])) {
                return false;
            } else {
                s++;
                e--;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        string temp = "";
        for (int j = 0; j < s.length(); j++) {
            if (valid(s[j])) {
                temp.push_back(s[j]);
            }
        }
        return checkPalindrome(temp);
    }
};