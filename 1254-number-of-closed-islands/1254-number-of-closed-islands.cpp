class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=1;
        int delr[]={1,0,-1,0};
        int delc[]={0,-1,0,1};
        bool flag=true;
        for(int k=0;k<4;k++){
            int newr=delr[k]+i;
            int newc=delc[k]+j;
            if(newr<0 || newr>=grid.size() || newc<0 || newc>=grid[0].size()){
                flag=false;
            }
            else{
                if(grid[newr][newc]==0){
                    if(!dfs(newr,newc,grid)){
                        flag=false;
                    };
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                
                if(dfs(i,j,grid)){
                    cnt++;
                }
                }
            }
        }
        return cnt;
    }
};