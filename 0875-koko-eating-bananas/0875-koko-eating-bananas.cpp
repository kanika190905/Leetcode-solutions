class Solution {
public:
    long long hoursNeeded(vector<int>& piles, int k) {
        long long total = 0;
        for(int p : piles){
            total += (p + k - 1) / k;   
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;

        int high = piles[0];
        for(int x : piles){
            high = max(high, x);
        }

        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(hoursNeeded(piles, mid) <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
