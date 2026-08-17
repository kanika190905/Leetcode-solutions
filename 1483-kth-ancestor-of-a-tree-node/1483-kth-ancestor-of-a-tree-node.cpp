class TreeAncestor {
public:
    int log=30;
    vector<vector<int>> up;
    TreeAncestor(int n, vector<int>& parent) {
        
         up.resize(log, vector<int>(n, -1));
          for(int i = 0; i < n; i++) {
            up[0][i] = parent[i];
        }
         for(int i=1;i<log;i++){
            for(int j=0;j<n;j++){
                if(up[i-1][j] != -1) {
    up[i][j] = up[i-1][up[i-1][j]];
}
               
            }
         }
    }
    
    int getKthAncestor(int node, int k) {
         int vv=node;
        for(int i=0;i<30;i++){
           
            if(k&(1<<i)){
                vv=up[i][vv];
                if(vv == -1){
                    return -1;
                }
  
            }
        }
        return vv;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */