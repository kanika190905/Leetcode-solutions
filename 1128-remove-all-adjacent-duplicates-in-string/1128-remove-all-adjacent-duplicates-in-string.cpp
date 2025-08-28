class Solution {
public:
    string removeDuplicates(string s) {
        string r;
        r.reserve(s.size());
        for(int i=0;i<s.size();i++){
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