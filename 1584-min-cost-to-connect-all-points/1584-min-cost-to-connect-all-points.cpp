class Solution {
public:
    int findWeight(int x1,int x2,int y1,int y2){
        return abs(x1-x2)+abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());
        int n=points.size();
        int node=0;
        for(int i=0;i<points.size();i++){
            int l=points[i][0];
            int r=points[i][1];
          for(int j=0;j<points.size();j++){
             if(j==i) continue;
             int ll=points[j][0];
             int rr=points[j][1];
             int dis=findWeight(l,ll,r,rr);
             adj[i].push_back({j,dis});
          }
        }
       priority_queue<
    pair<long long, int>,
    vector<pair<long long , int>>,
    greater<pair<long long, int>>
> pq;
 
        vector<long long> dist(n, 1e18);
 
        dist[0] = 0;
        pq.push({0, 0});
        vector<int> visited(n,0);
 
 
        while (!pq.empty()) {
 
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited[node]){
                continue;
            }
            visited[node]=1;
 
            for (auto it : adj[node]) {
 
                int adjNode = it.first;
                int edgeWeight = it.second;
 
                if (!visited[adjNode] && edgeWeight < dist[adjNode]) {
                    dist[adjNode] =  edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        long long sum=0;
       
     for (int i = 0; i < n; i++) {
   
    sum += dist[i];
}
return sum;
 
    }
};