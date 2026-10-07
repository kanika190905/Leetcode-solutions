class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() - k;

        int totalSum = 0;
        for(int i = 0; i < cardPoints.size(); i++) {
            totalSum += cardPoints[i];
        }

        int l = 0, r = 0;
        int sum = 0, mini = INT_MAX;

        while(r < cardPoints.size()) {
            sum += cardPoints[r];

            if(r - l + 1 > n) {
                sum -= cardPoints[l];
                l++;
            }

            if(r - l + 1 == n) {
                mini = min(mini, sum);
            }

            r++;
        }

        return totalSum - mini;
    }
};