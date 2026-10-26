class Solution {
public:
    long long dfs(int i,int j,vector<vector<int>>& grid){
        long long ans=grid[i][j];
        grid[i][j]=0;
        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newr=i+delr[k];
            int newc=j+delc[k];
            if(newr>=0 && newc>=0 && newr<grid.size() && newc<grid[0].size() && grid[newr][newc]!=0){
                ans+=dfs(newr,newc,grid);
            }
        }
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    if((dfs(i,j,grid))%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};