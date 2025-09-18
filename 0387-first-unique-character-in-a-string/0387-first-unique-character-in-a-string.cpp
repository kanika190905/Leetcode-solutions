class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        int count[26];
        for(int i=0;i<s.size();i++){
            char c=s[i];
            q.push(i);
            count[c-97]++;
            while(!q.empty() && count[s[q.front()]-97]>1){
                q.pop();
            }
        }
        if(!q.empty()){
            return q.front();
        }
        return -1;
    }
};