class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi=INT_MIN,smaxi=INT_MIN,tmaxi=INT_MIN;
        int mini=INT_MAX,smini=INT_MAX;
        
       for(int x:nums){
           
            if(x>=maxi){
                tmaxi=max(tmaxi,smaxi);
                smaxi=max(maxi,smaxi);
                maxi=x;
            }
            else if(x>=smaxi){
                tmaxi=max(tmaxi,smaxi);
                smaxi=max(x,smaxi);
            }
            else{
               tmaxi=max(tmaxi,x); 
            }
            if(x<=mini){
                smini=mini;
                mini=x;
            }
            else if(x<=smini){
                smini=x;
            }
           
        }
        int ans1=maxi*smaxi*tmaxi;
        int ans2=maxi*mini*smini;
        if(ans1>ans2) return ans1;
        return ans2;
    }
};