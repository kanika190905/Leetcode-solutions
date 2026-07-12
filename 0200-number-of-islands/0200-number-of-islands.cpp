class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') return ;
        grid[i][j]='0';
        int delr[]={1,0,-1,0};
        int delc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newr=i+delr[k];
            int newc=j+delc[k];
            dfs(newr,newc,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]=='1'){
                dfs(i,j,grid);
                cnt++;
               } 
            }
        }
        return cnt;
    }
};