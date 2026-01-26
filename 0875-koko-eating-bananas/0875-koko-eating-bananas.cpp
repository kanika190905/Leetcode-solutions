class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
      int l=1,hi=INT_MIN,ans;
      int n=piles.size();
      for(int i=0;i<piles.size();i++){
        hi=max(hi,piles[i]);
      }
      ans=hi;
      while(l<=hi){
        int mid=l+(hi-l)/2;
        long long int k=0;
        for(int i=0;i<n;i++){
          k += (long long)ceil((double)piles[i] / mid);
        }
        if(k<=h){
            ans=mid;
            hi=mid-1;
        }
        else{
            l=mid+1;
        }
      }  
      return ans;
    }
};
