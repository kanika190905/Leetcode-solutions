class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=i;j<c;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int j=0;j<c/2;j++){
            for(int i=0;i<r;i++){
                swap(matrix[i][j],matrix[i][c-1-j]);
            }
        }
    }
};