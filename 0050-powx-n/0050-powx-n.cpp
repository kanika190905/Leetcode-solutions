class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        if(n<0){
            nn=(-nn);
            x=(1/x);
        }
        return power(x,nn);
    }
    double power(double x,long long nn){
        if(nn==0) return 1;
        double half=power(x,nn/2);
        if(nn%2==0){
            return half*half;
        }
        else{
            return half*half*x;
        }
    }
};