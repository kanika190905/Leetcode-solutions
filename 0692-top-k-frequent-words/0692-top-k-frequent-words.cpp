class Solution {
public:

    struct cmp {
        bool operator()(pair<int,string> a, pair<int,string> b) {
            if(a.first != b.first)
                return a.first < b.first;

            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        priority_queue<pair<int,string>,
                       vector<pair<int,string>>,
                       cmp> q;

        unordered_map<string,int> mp;

        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        for(auto it:mp){
            q.push({it.second,it.first});
        }

        while(k){
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }

        return ans;
    }
};