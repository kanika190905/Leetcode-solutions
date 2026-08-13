class Solution {
public:
    int solve(int n){
        if(n==0){
            return 0;
        }
        if((n&(n-1))==0) return 1;
        int low=1;
        while(low*2<n){
            low*=2;
        }
        int high=low*2;
        return 1+min(solve(n-low),solve(high-n));
    }
    int minOperations(int n) {
        return solve(n);
    }
};