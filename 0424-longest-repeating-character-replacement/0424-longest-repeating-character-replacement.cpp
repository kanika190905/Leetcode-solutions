class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxi=INT_MIN,maxFreq=0;
        vector<int> v(26,0);
       while(r<s.size()){
            v[s[r]-65]++;
            maxFreq=max(maxFreq, v[s[r]-65]);
            while(r-l+1-maxFreq > k){
                v[s[l]-65]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
       } 
       return maxi;
    }
};