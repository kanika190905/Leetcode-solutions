class Solution {
public:
    int helper(int i, bool alice,int m, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if (i >= piles.size()) return 0;

        int stones=0;
        int result=(alice==1)? INT_MIN:INT_MAX;
        if (dp[i][m][alice] != -1)
            return dp[i][m][alice];

        for(int x=1;x<=min(2*m,(int)piles.size()-i);x++){
            stones+=piles[i+x-1];
            if(alice){
                result=max(result,stones+helper(i+x,0,max(m,x),piles,dp));
            }
            else{
                result=min(result,helper(i+x,1,max(m,x),piles,dp));
            }
        }
        

        return  dp[i][m][alice]=result;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(
    n,
    vector<vector<int>>(n + 1,
        vector<int>(2, -1)
    )
);

        return helper(0,1, 1, piles, dp);
    }
};