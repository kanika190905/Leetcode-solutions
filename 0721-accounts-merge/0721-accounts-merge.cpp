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
        int findPar(int node){
            if(parent[node]==node) return node;
            return parent[node]=findPar(parent[node]);
        }
        void unionByRank(int u,int v){
            int pu=findPar(u);
            int pv=findPar(v);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        int n=accounts.size();
        DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    ds.unionByRank(i,mp[mail]);
                }
            }
        }
        vector<string> mergedMail[n];
        for(auto it:mp){
            string mail=it.first;
            int node=ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};