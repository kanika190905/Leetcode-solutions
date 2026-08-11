class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], {0, 0}});

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto [time,it]=pq.top();
            pq.pop();
            int r=it.first;
            int c=it.second;
            if(r==n-1 && c==m-1) return time;
            if(time>dist[r][c]) continue;
           
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int maxi=max(time,grid[nr][nc]);
                    if(maxi<dist[nr][nc]){
                        dist[nr][nc]=maxi;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};