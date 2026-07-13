class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size()==1) return 1;
        int maxi=INT_MIN,l=0,r=1;
        vector<int> m(256,0);
        m[s[l]]=1;
        while(r<s.size()){
            while(m[s[r]]!=0){
                m[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            m[s[r]]+=1;
            r++;
        }
        return maxi;
    }
};