class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        if(groupSize==1) return true;
        unordered_map<int,int> freq;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x:hand){
            freq[x]++;
            if(freq[x]==1){
                pq.push(x);
            }
        }
        int k=groupSize;
        int n=hand.size()/groupSize;
        int prev=-1;
        vector<int> temp;
        while(!pq.empty() || !temp.empty()){
            if(k==0){
                k=groupSize;
                for(int y:temp){
                    pq.push(y);
                }
                temp.clear();
                prev=-1;
            }
           int curr=pq.top();
           pq.pop();
           if(prev!=-1 && curr-prev!=1) return false;
           k--;
           freq[curr]--;
           prev=curr;
           if(freq[curr]){
            temp.push_back(curr);
           }
        }
        for(auto x:freq){
            if(freq[x.first]!=0) return false;
        }
        return true;
    }
};