class Solution {
public:
    int idx=-1,start=-1;
    void dfs(int node,vector<vector<int>>& adj,vector<int> &visited,vector<int> &parent){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                parent[it]=node;
                dfs(it,adj,visited,parent);
                if(idx != -1) return;
            }
            else if(parent[node]!=it){
                idx=node;
                start=it;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(adj.size(),0);
        vector<int> parent(adj.size(),-1);
        dfs(1,adj,visited,parent);
        vector<int> temp;
        int x=idx;
        while(idx!=start){
            temp.push_back(idx);
            idx=parent[idx];
        }
        temp.push_back(idx);
        temp.push_back(x);
        reverse(temp.begin(),temp.end());
        for(int i=edges.size()-1;i>=0;i--){
            int u=edges[i][0];
            int v=edges[i][1];
            for(int j=0;j<temp.size()-1;j++){
                if((temp[j]==u && temp[j+1]==v) || (temp[j]==v && temp[j+1]==u)){
                    return {u,v};
                }
            }
        }
        return {};
    }
};