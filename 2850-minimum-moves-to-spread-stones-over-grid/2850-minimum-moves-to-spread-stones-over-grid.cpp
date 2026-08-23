class Solution {
public:
    int dfs(vector<vector<int>>& grid){
        int r=-1,c=-1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        if(r==-1) return 0;
        int ans=1e9;
         for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]>1){
                    int dist=abs(i-r)+abs(j-c);
                    grid[i][j]--;
                    grid[r][c]=1;
                    ans=min(ans,dist+dfs(grid));
                    grid[i][j]++;
                    grid[r][c]--;
                }
            }
        }
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        return dfs(grid);
    }
};