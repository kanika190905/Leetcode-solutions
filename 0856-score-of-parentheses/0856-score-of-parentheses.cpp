class Solution {
public:
    int scoreOfParentheses(string s) {
       int cnt=0;
       int open=0,i=0;
       while(i<s.size()){
        if(s[i]=='('){
            open++;
            i++;
        }
        else if(s[i]==')'){
            open--;
            if(s[i-1]=='('){
                cnt+=pow(2, open);
            }
            i++;
        }
       } 
       return cnt;
    }
};