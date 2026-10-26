class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<pair<int,int>,int> mp;
        set<int> s;
        int cnt=0;
        for(auto it:pick){
            mp[{it[0],it[1]}]++;
            if((mp[{it[0],it[1]}]==it[0]+1)&& (s.find(it[0])==s.end())){ s.insert(it[0]);cnt++;}
        }
        
        return cnt;
    }
};