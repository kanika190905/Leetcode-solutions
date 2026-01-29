class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,cnt=0;
        vector<int> v(3,0);
        while(r<s.size()){
            v[s[r]-'a']++;
                while(v[0]>=1 && v[1]>=1 && v[2]>=1){
                    cnt+=s.size()-r;
                    v[s[l]-'a']--;
                    l++;
                }
            
            r++;
        }
        return cnt;
    }
};