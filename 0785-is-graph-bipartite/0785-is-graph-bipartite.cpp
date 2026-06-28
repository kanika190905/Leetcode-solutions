class Solution {
public:
     
      bool dfs(int node, int col, int color[], vector<vector<int>>& adj) {
        color[node] = col; 
        
        // traverse adjacent nodes
        for(auto it : adj[node]) {
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int color[graph.size()];
	    for(int i = 0;i<graph.size();i++) color[i] = -1; 
	    
	    // for connected components
	    for(int i = 0;i<graph.size();i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, graph) == false) 
	                return false; 
	        }
	    }
	    return true; 
	} 
    
};