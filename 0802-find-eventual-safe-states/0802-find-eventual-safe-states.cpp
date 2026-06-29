class Solution {
public:
bool dfs(int node,vector<bool>& vis,vector<bool>& pathvis,vector<vector<int>>& adj,vector<bool>& check){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
               if( dfs(it,vis,pathvis,adj,check)) return true;
            }
            else if(pathvis[it]){
                 return true;
            }
        }
        pathvis[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,0);
        vector<bool> check(n,0);
        vector<bool> pathvis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
                if(!vis[i]){
                     dfs(i,vis,pathvis,graph,check);
                }
            }
            for(int i=0;i<n;i++){
                            if(check[i]){
                                ans.push_back(i);
                            }
                        }
            return ans;
    }
};