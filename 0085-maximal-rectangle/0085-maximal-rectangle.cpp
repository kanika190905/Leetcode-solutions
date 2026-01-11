class Solution {
    int maxArea(vector<int> &arr){
        stack<int> s;
        int n=arr.size();
        int maxi=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || arr[i]<arr[s.top()])){
                int element=arr[s.top()];
                s.pop();

                int nse=i;
                int pse=s.empty()?-1:s.top();

                maxi=max(maxi,element*(nse-pse-1));
            }
            s.push(i);
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> prefixSum(r,vector<int>(c));
        for(int j=0;j<c;j++){
            int sum=0;
            for(int i=0;i<r;i++){
                if(matrix[i][j]=='1'){
                    sum++;
                }
                else{
                    sum=0;
                }
                prefixSum[i][j]=sum;
            }
        }
        int maxi=0;
        for(int i=0;i<r;i++){
            maxi=max(maxi,maxArea(prefixSum[i]));
        }
        return maxi;
    }
};