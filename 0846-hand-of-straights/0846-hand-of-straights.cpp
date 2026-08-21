class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int> freq;
        for(int x:hand){
            freq[x]++;
        }
        int k=groupSize;
        for(auto [x,cnt]:freq){
            if(freq[x]==0) continue;
            for(int i=0;i<k;i++){
                if(freq[x+i]==0) return false;
                freq[x+i]-=cnt;
            }
        }
        return true;
    }
};