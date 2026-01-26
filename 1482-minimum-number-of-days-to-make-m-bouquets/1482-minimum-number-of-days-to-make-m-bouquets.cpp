
class Solution {
public:
    bool possible(vector<int>& a,int day, int m, int k){
        int n=a.size();
        int cnt=0,bouq=0;
        for(int i=0;i<n;i++){
            if(a[i]<=day){
                cnt++;
                if(cnt==k){
                    bouq++;
                    cnt=0;
                }
            }
            else cnt=0;
        }
        return bouq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       int l=INT_MAX,h=INT_MIN;
       long long n = bloomDay.size();
       if((long long)m * k > n) return -1;
       for(int i=0;i<bloomDay.size();i++){
        l=min(l,bloomDay[i]);
        h=max(h,bloomDay[i]);
       } 
       int ans=h;
       while(l<=h){
        int mid=l+(h-l)/2;
        if(possible(bloomDay,mid,m,k)){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
       }
       return ans;
    }
};
