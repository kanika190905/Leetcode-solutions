class Solution {
public:

class DisjointSet {

public:
vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n , 0);
        parent.resize(n);
        size.resize(n );

        for (int i = 0; i <n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Find with Path Compression
    int findPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }
 void unionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
    int largestIsland(vector<vector<int>>& grid) {
        DisjointSet dsu(grid.size()*grid[0].size());
        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                for(int k=0;k<4;k++){
                    int newr=i+delr[k];
                    int newc=j+delc[k];
                    if(newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size() && grid[newr][newc]==1){
                        dsu.unionBySize((i*grid[0].size())+j,(newr*grid[0].size()+newc));

                    }
                    
                }
                }
            }
        }
        
        int maxi=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;
                for(int k=0;k<4;k++){
                    int newr=i+delr[k];
                    int newc=j+delc[k];
                    if(newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size() && grid[newr][newc]==1){
                        
                            st.insert(dsu.findPar(newr*grid[0].size()+newc));
                        

                    }
                    
                }
                int sizee=0;
                for(auto it:st){
                    sizee+=dsu.size[it];
                }
                maxi=max(maxi,sizee+1);
                
                }
            }
        }
        if(maxi == INT_MIN)
    return grid.size() * grid[0].size();

return maxi;
    }
};