class Solution {
public:
    int reverse(int x) {
        int ans=0,n=10;
        ans=(ans)+(x%10);
        x=x/10;
        while(abs(x)>0){
            if(((long long)n*ans > INT_MAX) || ((long long)n*ans < INT_MIN))return 0;
            ans=(n*ans)+(x%10);
            x=x/10;
        }
        return ans;
    }
};