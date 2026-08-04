class Solution {
public:
    bool check(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if( j==s2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
    return a.size() < b.size();
});
        vector<int> dp(words.size(),1);
        int maxi=1,last_idx=0;
        for(int idx=0;idx<words.size();idx++){
          
            for(int prev_idx=0;prev_idx<idx;prev_idx++){
                if(check(words[idx],words[prev_idx]) && dp[idx]<dp[prev_idx]+1){
                dp[idx]=dp[prev_idx]+1;
               
                }
            }
            if(dp[idx]>maxi){
            maxi=max(maxi,dp[idx]);
            }
        }
        return maxi;
    }
};