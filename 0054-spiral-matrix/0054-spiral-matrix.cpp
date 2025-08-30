class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> neww;
        int r=matrix.size();
        int c=matrix[0].size();
        neww.reserve(r*c);
        int SR=0,SC=0;
        int EC=c-1;
        int ER=r-1;
        int n=r*c;
        int count=0;
        while(count<n){
            for(int i=SC;i<=EC && count<n ;i++){
                neww.push_back(matrix[SR][i]);
                count++;
            }
            SR++;
            for(int i=SR;i<=ER && count<n ;i++){
                neww.push_back(matrix[i][EC]);
                count++;
            }
            EC--;
            for(int i=EC;i>=SC && count<n ;i--){
                neww.push_back(matrix[ER][i]);
                count++;
            }
            ER--;
            for(int i=ER;i>=SR && count<n ;i--){
                neww.push_back(matrix[i][SC]);
                count++;
            }
            SC++;
        }
        return neww;
    }
};