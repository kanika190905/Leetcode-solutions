class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int maxi=0;
       for(int i=0;i<gain.size();i++){
        if(i==0){
             maxi=max(maxi,gain[i]);
        }
        else{
            maxi=max(maxi,gain[i]+gain[i-1]);
            gain[i]+=gain[i-1];}
       } 
       return maxi;
    }
};