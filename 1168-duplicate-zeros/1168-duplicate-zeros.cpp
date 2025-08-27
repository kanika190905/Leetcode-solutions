class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                count++;
            }
        }
        int i=n-1;
        int j=n+count-1;
        while(i>=0 && j>=0){
            if(arr[i]!=0){
                if(j<n) arr[j]=arr[i];
                j--;
                i--;
            }
            else{
                if(j<n) arr[j]=arr[i];
                if(j-1<n && j-1>=0) arr[j-1]=0;
                i--;
                j-=2;
            }
        }
    }
};