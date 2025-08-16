class Solution {
public:
    bool ispossible(vector<int>& position,int mid,int m){
        int lastpos=position[0];
        int ballcount=1;
        for(int i=1;i<position.size();i++){
            if(position[i] - lastpos >= mid){
                ballcount++;
                lastpos=position[i];
                if(ballcount==m){
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=0;
        int maxi=-1;
        for(int i=0;i<position.size();i++){
            maxi=max(maxi,position[i]);
        }
        int e=maxi;
        int ans=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(position,mid,m)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};