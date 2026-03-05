class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int i1=text1.size();
        int i2=text2.size();
        vector<vector<int>> dp(i1+1,vector<int>(i2+1,-1));
        for(int i=0;i<=i2;i++) dp[0][i]=0;
        for(int i=0;i<=i1;i++) dp[i][0]=0;
        for(int i=1;i<=i1;i++){
             for(int j=1;j<=i2;j++){
                if(text1[i-1]==text2[j-1]){
             dp[i][j]=1+dp[i-1][j-1];
        }
        else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             }
        }
        //printing 
        //o(m+n)
        string s="";
        int len=text1.length()+text2.length()-dp[i1][i2];
        for(int i=0;i<len;i++){
            s+='$';
        }
        int idx=len-1;
        int k=i1,l=i2;
        while(k>0 && l>0){
            if(text1[k-1]==text2[l-1]){
                s[idx]=text1[k-1];
                k--;
                l--;
                idx--;
            }
            else if(dp[k-1][l]>dp[k][l-1]){
                s[idx]=text1[k-1];
                k--;idx--;
            }
            else{
                s[idx]=text2[l-1];
                l--;idx--;
            }
        }
        while(k>0){
            s[idx]=text1[k-1];
            k--;idx--;
        }
        while(l>0){
            s[idx]=text2[l-1];
            l--;idx--;
        }
        //end
        return s;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return longestCommonSubsequence(str1,str2);
    }
};