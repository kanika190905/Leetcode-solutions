class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxi=0;
        int n=heights.size();
        for(int i=0;i<=heights.size();i++){
            while(!s.empty() &&(i==n || heights[i]<heights[s.top()])){
                int element=heights[s.top()];
                s.pop();

                int nse=i;
                int pse=s.empty()?-1:s.top();

                maxi=max(maxi,element*(nse-pse-1));
            }
            s.push(i);
        }
        return maxi;
    }
};