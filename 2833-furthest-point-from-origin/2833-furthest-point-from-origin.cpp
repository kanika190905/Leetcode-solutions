class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                l++;
                r--;
            }
            else if(moves[i]=='R'){
                r++;
                l--;
            }
            else{
                l++;
                r++;
            }
        }
        return max(l,r);
    }
};