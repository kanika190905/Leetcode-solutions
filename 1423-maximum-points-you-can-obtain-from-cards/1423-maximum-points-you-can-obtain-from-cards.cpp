class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size()-k;
        int totalSum=0;
        for(int i=0;i<cardPoints.size();i++){
            totalSum+=cardPoints[i];
        }
        int l=0,r=0,sum=0,mini=INT_MAX,cnt=0;
        while(r<cardPoints.size()){
            cnt++;
            if(cnt>n && l!=cardPoints.size()-1){
                sum-=cardPoints[l];
                l++;
                cnt--;
            }
            sum+=cardPoints[r];
            if(cnt==n)
            mini=min(mini,sum);
            r++;
        }
        return totalSum-mini;
    }
};