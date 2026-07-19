class Solution {
public:
    int gcd(int a,int b){
        if(a==0) return b;
        else return gcd(b%a,a);
    }
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1));
    }
};