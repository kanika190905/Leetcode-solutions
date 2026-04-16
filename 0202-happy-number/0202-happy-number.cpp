class Solution {
public:
    bool isHappy(int n) {
        int ans,finalans;
        while(n != 1 && n != 4){
            int x=n;
             ans=0;
            while(x>0){
                int y=x%10;
                ans+=(y*y);
                x=x/10;
            }
            n=ans;
            finalans=ans;
           
        }
        if(ans==1) return true;
        return false;
    }
};