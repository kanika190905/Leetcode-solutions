class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> m(0);
        unordered_map<char,int> m2(0);
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(m2[toupper(word[i])]>0 && m[tolower(word[i])]>0 ) continue;
             if(word[i]-'a'>=0 && word[i]-'a'<26){
                if(m2[toupper(word[i])]){
                    cnt++;
                }
                
                    m[word[i]]++;
             }
             else{
                if(m[tolower(word[i])]){
                    cnt++;
                }
                
                    m2[word[i]]++;
             }
        }
        return cnt;
    }
};