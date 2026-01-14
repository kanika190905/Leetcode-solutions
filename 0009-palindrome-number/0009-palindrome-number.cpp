class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int y=x;
        int ans=0,n=10;
        ans=(ans)+(x%10);
        x=x/10;
        while(x>0){
            if(((long long)n*ans > INT_MAX) || ((long long)n*ans < INT_MIN))return false;
            ans=(n*ans)+(x%10);
            x=x/10;
        }
       if(ans==y) return true;
       else return false;
    }
};