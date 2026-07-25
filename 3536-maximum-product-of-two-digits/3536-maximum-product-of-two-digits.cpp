class Solution {
public:
    int maxProduct(int n) {
        int maxi=INT_MIN,smaxi=INT_MIN;
        
        while(n){
            int x=n%10;
            if(x>=maxi){
                smaxi=max(maxi,smaxi);
                maxi=x;
            }
            else{
                smaxi=max(x,smaxi);
            }
            n/=10;
        }
        
        return maxi*smaxi;
    }
};