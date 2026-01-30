class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size()-k;
        int totalSum=0;
        for(int i=0;i<cardPoints.size();i++){
            totalSum+=cardPoints[i];
        }
        if(k==cardPoints.size()) return totalSum;
        int l=0,r=0,sum=0,mini=INT_MAX;
        while(r<cardPoints.size()){
            if(r-l+1 > n){
                sum-=cardPoints[l];
                l++;
            }
            sum+=cardPoints[r];
            if(r-l+1 ==n)
            mini=min(mini,sum);
            r++;
        }
        return totalSum-mini;
    }
};