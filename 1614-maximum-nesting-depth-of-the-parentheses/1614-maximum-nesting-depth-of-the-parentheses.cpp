class Solution {
public:
    int maxDepth(string s) {
        int maxi=0,cnt=0;
        for(char x:s){
            if(x=='('){
                cnt+=1;
                maxi=max(maxi,cnt);
            }
            else if(x==')'){
                cnt-=1;
            }
        }
        return maxi;
    }
};