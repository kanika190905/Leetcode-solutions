class Solution{
public:
    int shortestPath(int n,vector<vector<int>>&edges,string labels,int k){
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[2],it[1]});
        }
        vector<vector<int>>dist(n,vector<int>(k+1,1e9));
        pq.push({0,0,1});
        dist[0][1]=0;
        while(!pq.empty()){
            auto[weight,node,cnt]=pq.top();
            pq.pop();
            if(weight>dist[node][cnt])continue;
            for(auto[wt,next]:adj[node]){
                int newCnt;
                if(labels[node]==labels[next])newCnt=cnt+1;
                else newCnt=1;
                if(newCnt>k)continue;
                if(weight+wt<dist[next][newCnt]){
                    dist[next][newCnt]=weight+wt;
                    pq.push({weight+wt,next,newCnt});
                }
            }
        }
        int ans=*min_element(dist[n-1].begin(),dist[n-1].end());
        return ans==1e9?-1:ans;
    }
};