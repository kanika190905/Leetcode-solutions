class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<int,int> m;
        unordered_map<int,int> m2;
        for(int i=0;i<s.size();i++){
            
            if(m[s[i]] && m[s[i]]!=t[i]) return false;
            else if(m2[t[i]] && m2[t[i]]!=s[i]) return false;
            
            m[s[i]]=t[i];
            m2[t[i]]=s[i];
        }
        return true;
    }
};