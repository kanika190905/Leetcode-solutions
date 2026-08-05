class Solution {
public:
    void dfs(int node, vector<int>& visited,vector<vector<int>>& adj){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        if(invocations.empty()){
            vector<int> ans;
            for(int i=0;i<n;i++) {
                if(i!=k)ans.push_back(i);}
            return ans;
        }
       vector<vector<int>> adj(n);
       for(int i=0;i<invocations.size();i++){
        int u=invocations[i][0];
        int v=invocations[i][1];
        adj[u].push_back(v);
       } 
       vector<int> visited(n,0);
       dfs(k,visited,adj);
       vector<int> ans;
       for(int i=0;i<n;i++){
        if(!visited[i]){
            ans.push_back(i);
        }
      
       }
       bool flag=false;
       for(int x:ans){
        for(int y:adj[x]){
            if(visited[y]){
                flag=true;
                break;
            }
        }
       }
       if(flag==true){
        for(int i=0;i<n;i++){
        if(visited[i]){
            ans.push_back(i);
        }
      
       }
       }
       return ans;
    }
};