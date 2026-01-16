class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int l=0,h=r-1;
        int maxi,midc,mid;
        vector<int> ans;
        while(l<=h){
            mid=l+((h-l)/2);
            maxi=INT_MIN;
            for(int i=0;i<c;i++){
                if(maxi<mat[mid][i]){
                    maxi=mat[mid][i];
                    midc=i;
                }
            }
            int up=mid>0? mat[mid-1][midc]:-1;
            int down=mid<r-1? mat[mid+1][midc]:-1;
            if(mat[mid][midc]>up && mat[mid][midc]>down){
                ans.push_back(mid);
                ans.push_back(midc);
                break;
            }
            else{
                if(up>mat[mid][midc]) h=mid-1;
                else l=mid+1;
            }
            
        }
        return ans;
    }
};