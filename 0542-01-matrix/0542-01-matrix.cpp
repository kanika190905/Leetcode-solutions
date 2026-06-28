class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> time(mat.size(), vector<int>(mat[0].size(), 0));
        queue<pair<pair<int,int>,int>> q;
        int t=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                vis[i][j]=1;
                q.push({{i,j},0});
                }
            }
        }
        int delR[]={0,1,0,-1};
        int delC[]={1,0,-1,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int currT=q.front().second;
            q.pop();
             for(int i=0;i<4;i++){
                int nrow=row+delR[i];
                int ncol=col+delC[i];
                if(nrow<0 || ncol<0 || nrow>=mat.size() || ncol>=mat[0].size() || vis[nrow][ncol]==1){
                    continue;
                }
                vis[nrow][ncol]=1;
                t=currT+1;
                time[nrow][ncol]=t;
                q.push({{nrow,ncol},t});
             }
        }
        return time;

    }
};