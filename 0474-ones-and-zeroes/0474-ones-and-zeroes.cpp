class Solution {
public:
int count1(string s){
    int counter=0;
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'==1){
            counter++;
        }
        
    }
    return counter;
}
int count0(string s){
    int counter=0;
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'==0){
            counter++;
        }
        
    }
    return counter;
}
int solve(int indx,int n,int m,vector<string>&strs,vector<vector<vector<int>>> &dp){
    if(indx==strs.size()){
        return 0;
    }
    if(dp[n][m][indx]!=-1){
        return dp[n][m][indx];
    }
    int coun1=count1(strs[indx]);
    int coun0=count0(strs[indx]);
    int take=0;
    if(coun1<=n && coun0<=m){
        take=1+solve(indx+1,n-coun1,m-coun0,strs,dp);
    }
    int notTake=solve(indx+1,n,m,strs,dp);
    return dp[n][m][indx]=max(take,notTake);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,(vector<int>(strs.size()+1,-1))));
        int ans=solve(0,n,m,strs,dp);
        return ans;
    }
};