class Solution {
public:
    string removeDuplicates(string s) {
        string r;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(!r.empty() && r.back()==ch){
                r.pop_back();
            }
            else{
                r.push_back(ch);
            }
        }
        return r;
    }
};