class Solution {
public:
    bool isPalindrome(string& s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int f(int i,string& s,vector<int>& dp){
        if(i==s.size()) return 0;
        string temp="";
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            int cost=INT_MAX;
            if(isPalindrome(temp)){
                cost=1+f(j+1,s,dp);
            }
            mini=min(mini,cost);
           
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return f(0,s,dp)-1;
    }
};