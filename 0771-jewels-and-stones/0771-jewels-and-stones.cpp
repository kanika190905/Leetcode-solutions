class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
       unordered_map<int,int> m;
       for(int i=0;i<jewels.size();i++){
        m[jewels[i]]++;
       }
       int cnt=0;
       for(int i=0;i<stones.size();i++){
        if(m[stones[i]]>0){
            cnt++;
        }
       } 
       return cnt; 
    }
};