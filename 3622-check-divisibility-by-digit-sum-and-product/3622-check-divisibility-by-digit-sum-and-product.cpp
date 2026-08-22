class Solution {
public:
    int sum(int n){
        int s=0;
        while(n){
            int r=n%10;
            s+=r;
            n/=10;
        }
        return s;
    }
    int product(int n){
         int s=1;
        while(n){
            int r=n%10;
            s*=r;
            n/=10;
        }
        return s;
    }
    bool checkDivisibility(int n) {
        if((n%(sum(n)+product(n))==0)) return true;
        return false;
    }
};