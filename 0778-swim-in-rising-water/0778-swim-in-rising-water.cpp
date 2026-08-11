class Solution {
public:
class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n , 0);
        parent.resize(n);
        size.resize(n );

        for (int i = 0; i < n; i++) {
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
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> active(n,vector<bool>(n,false));
        DisjointSet dsu(grid.size()*grid[0].size());
        int start=0;
        int end=n*n-1;
         vector<pair<int,int>> pos(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
         int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i=0;i<(n*n);i++){
            int row=pos[i].first;
            int col=pos[i].second;
            active[row][col]=true;
            for(int k=0;k<4;k++){
                int newr=row+dr[k];
                int newc=col+dc[k];
                if(newr>=0 && newc>=0 && newr<n && newc<n && active[newr][newc]){
                    dsu.unionBySize(row*n+col,newr*n+newc);
                }
            }
            if(dsu.findPar(0)==dsu.findPar(n*n-1)){
                return i;
            }
        }
        return 0;
        
    }
};