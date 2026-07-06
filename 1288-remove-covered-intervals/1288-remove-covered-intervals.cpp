class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(),
    [](vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];  
        return a[0] < b[0];       
    });
    int i=0;
    int j=i+1;
        while(j<intervals.size() && i<intervals.size()-1){

            if( intervals[i][1]>=intervals[j][1]){
                n--;
                j++;
            }
            else{
                i=j;
                j++;
            }
        }
        return n;
    }
};