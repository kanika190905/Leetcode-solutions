class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findParent(int node) {
            if (parent[node] == node)
                return node;

            return parent[node] = findParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);

            if (pu == pv)
                return;

            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    ds.unionByRank(i, j);
                }
            }
        }

        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i)
                provinces++;
        }

        return provinces;
    }
};