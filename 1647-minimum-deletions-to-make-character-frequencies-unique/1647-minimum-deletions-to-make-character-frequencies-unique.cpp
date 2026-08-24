class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        set<char> st;
        int ans=0;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            st.insert(s[i]);
        }
        vector<int> visited(s.length()+1,0);
        for(auto x:st){
            int val=mp[x];
            if(!visited[val]){
                visited[val]=1;
            }
            else{
                for(int i=val-1;i>=0;i--){
                    if(visited[i]){
                        ans++;
                        continue;
                    }
                    else{
                        ans++;
                        visited[i]=1;
                        break;
                    }
                }

            }
        }
        return ans;
        
    }
};