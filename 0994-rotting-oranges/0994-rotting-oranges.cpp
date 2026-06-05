class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0,freshCnt=0,cnt=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) freshCnt++;
                else if(grid[i][j]==2){
                    q.push({{i,j},t});
                }
            }
        }
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int currT=q.front().second;
            q.pop();
            t=max(t,currT);
            for(int k=0;k<4;k++){
                int nrow=i+drow[k];
                int ncol=j+dcol[k];
                if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},currT+1});
                    grid[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=freshCnt) return -1;
        return t;
    }
};