class Solution {
public:
 void dfs(int r,int c,vector<vector<int>>& grid, vector<vector<int>> &vis)
{
   if( r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || vis[r][c] || grid[r][c]==0 ) return;
        vis[r][c]=1;
        dfs(r-1,c,grid,vis);
        dfs(r+1,c,grid,vis);
        dfs(r,c-1,grid,vis);
        dfs(r,c+1,grid,vis);
    

}  
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1){
                dfs(0,i,grid,vis);
            }
        }
        for(int i=0;i<grid[0].size();i++){
            if(grid[grid.size()-1][i]==1){
                dfs(grid.size()-1,i,grid,vis);
            }
        }
        for(int i=1;i<grid.size()-1;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
        }
        for(int i=1;i<grid.size()-1;i++){
            if(grid[i][grid[0].size()-1]==1){
                dfs(i,grid[0].size()-1,grid,vis);
            }
        }
         for(int i=1;i<grid.size()-1;i++){
             for(int j=1;j<grid[0].size()-1;j++){
               if(grid[i][j]==1 && vis[i][j]==0){
                cnt++;
               }
             }
         }
         return cnt;
    }
};