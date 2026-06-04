class Solution {
public:
    void dfs(int start,vector<vector<int>>& isConnected,vector<bool>& vis){
        vis[start]=1;
       for(int j=0;j<isConnected.size();j++){
            if(isConnected[start][j] == 1 && !vis[j]) {
            dfs(j, isConnected, vis);}
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
       vector<bool> vis(n,0);
       
        int ans=0;
        
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                ans++;
            }
        }
return ans;
    }
};