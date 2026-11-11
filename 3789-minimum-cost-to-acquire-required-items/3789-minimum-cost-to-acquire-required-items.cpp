class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       long long ans=(long long)max(need1,need2);
       ans*=costBoth;
       long long ans2=(long long)min(need1,need2);
       ans2*=costBoth;
       if(need1>need2){
        ans2+=(long long)(abs(need1-need2))*cost1;
       }
       else{
        ans2+=(long long)(abs(need1-need2))*cost2;
       }
       ans=min(ans,ans2);
       long long ans3=(long long)cost1*need1+(long long)cost2*need2;
       ans=min(ans,ans3);
       return ans;
    }
};