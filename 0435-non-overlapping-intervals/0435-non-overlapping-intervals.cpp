class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int cnt=1;
        int n=intervals.size();
        int i=0;
        int j=1;
        while(j<n){
            if(intervals[i][1]<=intervals[j][0]){
                cnt++;
                i=j;
            }
            j++;
        }
        return n-cnt;
    }
};