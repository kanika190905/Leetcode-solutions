class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int s=newInterval[0];
        int e=newInterval[1],i=0;
        int n=intervals.size();
        while(i<n && s>intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && e>=intervals[i][0]){
            s=min(s,intervals[i][0]);
            e=max(e,intervals[i][1]);
            i++;
        }
        ans.push_back({s,e});
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};