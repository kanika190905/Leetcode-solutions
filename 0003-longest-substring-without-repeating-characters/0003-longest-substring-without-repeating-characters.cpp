class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int maxi=INT_MIN,cnt=0,cnt2=0;
       int l=0,r=0;
       vector<int> m(256,-1);
        while(r<s.size()){
            if (m[s[r]]>=l){
                l=m[s[r]]+1;
            }
            cnt=r-l+1;
            maxi=max(maxi,cnt);
            m[s[r]]=r;
            r++;
        }
       return maxi;
    }
};