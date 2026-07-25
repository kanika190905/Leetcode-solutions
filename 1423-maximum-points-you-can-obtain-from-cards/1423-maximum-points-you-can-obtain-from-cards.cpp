class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int j=cardPoints.size()-1;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int l=k-1;
        int tempSum=sum;
        while(cardPoints.size()-j<=k && l>=0){
             tempSum-=cardPoints[l];
            l--;
            tempSum+=cardPoints[j];
            j--;
            sum=max(sum,tempSum);
        }
        return sum;
    }
};