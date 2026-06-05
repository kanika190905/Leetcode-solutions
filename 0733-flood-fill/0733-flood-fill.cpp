class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,int oldColor,int color){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() ||image[i][j]!=oldColor)
        return;
        image[i][j]=color;
        dfs(i-1,j,image,oldColor,color);
        dfs(i+1,j,image,oldColor,color);
        dfs(i,j-1,image,oldColor,color);
        dfs(i,j+1,image,oldColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(oldColor==color) return image;
        dfs(sr,sc,image,oldColor,color);
        return image;
    }
};