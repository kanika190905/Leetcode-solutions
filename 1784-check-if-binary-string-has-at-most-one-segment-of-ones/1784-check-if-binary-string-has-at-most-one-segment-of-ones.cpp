class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'&& cnt>1){
                return false;
            }
            else if(s[i]=='0' && cnt==1){
                cnt++;
            }
        }
        return true;
    }
};