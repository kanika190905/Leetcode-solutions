class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int val=0;
        priority_queue<int> q;
        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        }
        
        while(!q.empty()){
            int node1=q.top();
            q.pop();
            int node2=0;
            if(!q.empty()){
                node2=q.top();
                q.pop();
            }
            if(node1!=node2 && node2!=0){
                val=node1-node2;
                q.push(val);
            }
            else{
                if(node2==0) val=node1;
                else val=0;
            }
        }
        return val;
    }
};