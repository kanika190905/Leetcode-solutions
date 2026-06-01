class Solution {
public:
    int minimumCost(vector<int>& cost) {
       sort(cost.begin(),cost.end());
       int mini=0,val=0;
       for(int i=cost.size()-1;i>=0;i--){
        val++;
        if(val==3){ val=0;continue;}
        mini+=cost[i];
       } 
       return mini;
    }
};