class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int nn=flights.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<nn;i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int distance=it.second.second;
            if(stops>k) continue;
            for(auto itr:adj[node]){
                int adjNode=itr.first;
                int d=itr.second;
                if(distance+d<dist[adjNode] && stops<=k){
                    dist[adjNode]=distance+d;
                    q.push({stops+1,{adjNode,distance+d}});
                }
            }
        }
        if(dist[dst]!=1e9)
        return dist[dst];

        return -1;
    }
};