class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
       priority_queue<int> pq;
       vector<int> ans;
       for(auto it:queries){
        int start=it[0],end=it[1];
        pq.push(abs(start)+abs(end));
        if(pq.size()>k){
            pq.pop();
        }
        if(pq.size()==k){
          ans.push_back(pq.top());  
        }
        else{
            ans.push_back(-1);
        }
       } 
       return ans;
    }
};