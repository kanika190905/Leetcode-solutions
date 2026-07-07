class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : roads){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
    
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
        }
        vector<int> ways(n,0);
        vector<long long> dist(n,LONG_LONG_MAX);
        dist[0] = 0;
        ways[0]=1;
      priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>> q;
        q.push({0,0});
        const int MOD = 1000000007;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            long long distance=it.first;
            long long node=it.second;
            for(auto itr:adj[node]){
                long long adjNode=itr.first;
                long long d=itr.second;
                if(dist[adjNode]>d+distance){
                    dist[adjNode]=d+distance;
                    q.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dist[adjNode]==d+distance){
                    ways[adjNode]=(ways[adjNode]+ways[node])%(MOD);
                }
            }
        }
        return (ways[n-1]);

    }
};