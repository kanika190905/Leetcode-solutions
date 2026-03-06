class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        int minL=min(first.length(),last.length());
        string ans="";
        for(int i=0;i<minL;i++){
            if(first[i]!=last[i]){
                break;
            }
            ans+=first[i];
        }
        return ans;
    }
};