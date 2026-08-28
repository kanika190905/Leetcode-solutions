class Solution {
public:

    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
        int ans=0;
        for(int root=1;root<=i;root++){
            int left=dp[root-1];
            int right=dp[i-root];
            ans+=left*right;
            
        }
        dp[i]=ans;
        }
        return dp[n];
    }
};