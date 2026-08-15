class Solution {
public:
    char evaluate(vector<char>& temp,char operatorr){
        if(operatorr=='!'){
            if(temp[0]=='t') return 'f';
            else return 't';
        };
        if(operatorr=='&'){
            for(char x:temp){
                if(x=='f') return 'f';
            }
            return 't';
        }
        else{
            for(char x:temp){
                if(x=='t') return 't';
            }
            return 'f';
        }
    }
    bool parseBoolExpr(string expression) {
        string s=expression; // just to short the name
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==',') continue;
            if(s[i]==')'){
                vector<char> temp;
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char operatorr=st.top();
                st.push(evaluate(temp,operatorr));
            }
            else{
                st.push(s[i]);
            }
        }
        char ch=st.top();
        if(ch=='t') return true;
        return false;
    }
};