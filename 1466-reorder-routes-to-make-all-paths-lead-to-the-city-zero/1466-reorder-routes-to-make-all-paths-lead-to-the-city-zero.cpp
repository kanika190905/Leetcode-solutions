class Solution {
public:
int cnt=0;
    void dfs1(int node,vector<bool> &visited,vector<vector<pair<int,int>>>& adj){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it.first]){
                cnt+=it.second;
                dfs1(it.first,visited,adj);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
             adj[connections[i][1]].push_back({connections[i][0],0});
        }
        vector<bool> visited(n,0);
        dfs1(0,visited,adj);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
               dfs1(i,visited,adj); 
            }
        }
        return cnt;
    }
};