class Solution {
public:
    int climbStairs(int n,vector<int>& dp) {
       if(n==0) return 1;
       if(dp[n]!=-1) return dp[n];
       int left=0,right=0;
        if(n-1>=0)
       left=climbStairs(n-1);
       if(n-2>=0)
       right=climbStairs(n-2);
       return dp[n]=left+right; 
    }
    int climbStairs(int n) {
       vector<int> dp(n+1,-1);
      
       dp[0]=1;
       for(int i=1;i<=n;i++){
         int left=0,right=0;
         if(i-1>=0)
       left=dp[i-1];
       if(i-2>=0)
       right=dp[i-2];
       dp[i]=left+right;
       }
       
         return dp[n];
    }
};