class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board, vector<vector<int>> &vis)
{
   if( r<0 || c<0 || r>=board.size() || c>=board[0].size() || vis[r][c] || board[r][c]=='X' ) return;
        vis[r][c]=1;
        dfs(r-1,c,board,vis);
        dfs(r+1,c,board,vis);
        dfs(r,c-1,board,vis);
        dfs(r,c+1,board,vis);
    

}    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){
                dfs(0,i,board,vis);
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(board[board.size()-1][i]=='O'){
                dfs(board.size()-1,i,board,vis);
            }
        }
        for(int i=1;i<board.size()-1;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
        }
        for(int i=1;i<board.size()-1;i++){
            if(board[i][board[0].size()-1]=='O'){
                dfs(i,board[0].size()-1,board,vis);
            }
        }
         for(int i=1;i<board.size()-1;i++){
             for(int j=1;j<board[0].size()-1;j++){
               if(board[i][j]=='O' && vis[i][j]==0){
                board[i][j]='X';
               }
             }
         }
        
    }
};