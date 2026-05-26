class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> l(26,0);
        vector<int> u(26,0);
        
        int cnt=0;
        for(int i=0;i<word.size();i++){
           if(isupper(word[i])) u[word[i]-'A']++;
           else l[word[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(l[i] && u[i]) cnt++;
        }
        return cnt;
    }
};