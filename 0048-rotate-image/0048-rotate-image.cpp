class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=i+1;j<c;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<r;i++){
            int s=0,e=c-1;
            while(s<e){
                swap(matrix[i][s++],matrix[i][e--]);
            }
        }
    }
};