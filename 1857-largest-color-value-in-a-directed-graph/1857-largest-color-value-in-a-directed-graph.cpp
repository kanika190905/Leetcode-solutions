class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(colors.size());
        if(edges.size()==1 && edges[0][0]==edges[0][1]) return -1;
        vector<int> indegree(colors.size(),0);
        for(auto it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<colors.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int n=colors.size();
        vector<vector<int>> dp(n,vector<int>(26,0));
        int maxi=-1,visited=0;
        while(!q.empty()){
            int x=q.front();
            visited++;
            dp[x][colors[x]-'a']++;
            maxi=max(maxi,dp[x][colors[x]-'a']);
            q.pop();
            for(auto it:adj[x]){
               indegree[it]--;
               for(int i=0;i<26;i++){
                dp[it][i]=max(dp[it][i],dp[x][i]);
               }
               if(indegree[it]==0){
                q.push(it);
               } 
            }
        }
        if(visited!=n) return -1;
       
        return maxi;

    }
};