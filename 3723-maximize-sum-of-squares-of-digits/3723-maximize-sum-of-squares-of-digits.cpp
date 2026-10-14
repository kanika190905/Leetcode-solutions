class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9 <sum) return "";
       string ans="";
        while(sum>=9 && num>0){
           ans+='9';
            num--;
            sum-=9;
        }
        char c=sum+'0';
        if(num>0){
            ans+=c;
            num--;
            while(num>0){
                ans+='0';
                num--;
            }
        }
        return ans;
    }
};