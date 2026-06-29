class Solution {
public:
    bool dfs(int node,vector<bool>& vis,vector<bool>& pathvis,vector<vector<int>>& adj){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
               if( dfs(it,vis,pathvis,adj)) return true;
            }
            else if(pathvis[it]){
                 return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses,0);
        vector<bool> pathvis(numCourses,0);
          for (auto &it : prerequisites) {
             int a = it[0];
             int b = it[1];

            adj[b].push_back(a);   // b -> a
            }
            for(int i=0;i<numCourses;i++){
                if(!vis[i]){
                    if(dfs(i,vis,pathvis,adj)){return false;};
                }
            }
            return true;
    }
};