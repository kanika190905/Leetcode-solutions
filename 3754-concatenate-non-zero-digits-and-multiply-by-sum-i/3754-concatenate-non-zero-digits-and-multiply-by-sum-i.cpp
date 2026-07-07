class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0,x,i=1;
        while(n){
            int r=n%10;
            if(r!=0){
                x+=(r*i);
                i*=10;
            }
            sum+=r;
            n=n/10;
        }
       return sum*x;
    }
};