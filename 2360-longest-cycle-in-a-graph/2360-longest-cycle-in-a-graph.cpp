class Solution {
public:
    int last=-1,start=-1;
    bool dfs(int node,vector<char> &color,vector<vector<int>> &adj,vector<int>& parent){
        color[node]='G';
        for(auto it:adj[node]){
            if(color[it]=='W'){
                if(dfs(it,color,adj,parent)) {
                    parent[it]=node;
                    color[node] = 'B';
                    if(start!=-1) return true;
                    return true;}
            }
            else{
                if(color[it]=='G') {
                    parent[it]=node;
                    color[node] = 'B';
                    start=node;
                    last=it;
                    return true;
                }
            }
        }
        color[node]='B';
        return false;
    }
    int longestCycle(vector<int>& edges) {
        vector<vector<int>> adj(edges.size());
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
        }
        vector<char> color(edges.size(),'W');
        vector<int> parent(edges.size(),-1);
        int maxi=INT_MIN;
        vector<int> ans;
        bool flag=0;
        for(int i=0;i<edges.size();i++){
            if(color[i]=='W'){
                ans.clear();
                if(dfs(i,color,adj,parent)){
    
                    int x=last;
                    ans.push_back(start);
                    while(start!=x){
                        start=parent[start];
                        ans.push_back(start);
                    }
                    flag=1;
                    int y=ans.size();
                    maxi=max(maxi,y);
                }
            }
        }
        if(!flag){
            return -1;
        }
        else{
            return maxi;
        }
    }
};