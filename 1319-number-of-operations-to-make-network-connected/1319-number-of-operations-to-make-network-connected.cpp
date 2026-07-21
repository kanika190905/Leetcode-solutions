class Solution {
public:
    class DSU{
        public:
        vector<int> parent,rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(parent[node]==node) return node;
            return parent[node]=findParent(parent[node]);
        }
        void unionByRank(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv) return;
            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }
            else if(rank[pv]>rank[pu]){
                parent[pu]=pv;
            }
            else{
                parent[pv]=pu;
                rank[pu]++;
            }
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
       DSU ds(n);
       int cntExtras=0;
       for(auto it:connections){
        int u=it[0];
        int v=it[1];
        if(ds.findParent(u)==ds.findParent(v))
           cntExtras++;
        else
            ds.unionByRank(u,v);
       }
       int cnt=0;
       for(int i=0;i<n;i++){
        if(ds.parent[i]==i) cnt++;
       }
       if(cntExtras>=(cnt-1)) return cnt-1;
       return -1;
    }
};