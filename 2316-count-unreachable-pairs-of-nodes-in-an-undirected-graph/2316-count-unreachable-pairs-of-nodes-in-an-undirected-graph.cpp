class Solution {
public:
    long long dfs(int node,vector<int> &visited,vector<vector<int>>& adj){
        visited[node]=1;
        long long cnt=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                cnt+=dfs(it,visited,adj);
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<long long> comp;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long temp=dfs(i,vis,adj);
                comp.push_back(temp);
            }
        }
        long long ans=0;
        
        for(int i=0;i<comp.size()-1;i++){
           ans+=(comp[i]*(n-comp[i]));
           n-=comp[i]; 
        }
        
        return ans;
    }
};