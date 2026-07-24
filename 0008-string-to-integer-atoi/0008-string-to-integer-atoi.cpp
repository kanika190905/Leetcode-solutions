class Solution {
public:
    int myAtoi(string s) {
        long long x=0;
        int sign=1;
        int i=0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        if(i == s.size()) return 0;
        if(s[i]=='-'|| s[i]=='+'){
            if(s[i]=='-')
            sign=-1;
             i++;
        }
       
       
        while(i<s.size() && isdigit(s[i])){
           int digit = s[i] - '0';

        if (sign == 1) {
         if (x > INT_MAX / 10 || (x == INT_MAX / 10 && digit > 7))
        return INT_MAX;
        } else {
        if (x > INT_MAX / 10 || (x == INT_MAX / 10 && digit > 8))
        return INT_MIN;
            }

          x = x * 10 + digit;
            i++;
        }
        return (int)(x*sign);
        
    }
};