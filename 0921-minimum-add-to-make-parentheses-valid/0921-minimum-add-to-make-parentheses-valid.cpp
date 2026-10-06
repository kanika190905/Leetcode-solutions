class Solution {
public:
    int minAddToMakeValid(string s) {
        int val=0;
        int ans=0;

        for(int i=0;i<s.length();i++){

            if(s[i]=='('){
                val++;
            }
            else{
                val--;

                if(val < 0){
                    ans++;
                    val=0;
                }
            }
        }

        return ans+val;
    }
};