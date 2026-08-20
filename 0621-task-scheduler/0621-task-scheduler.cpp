class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int x:tasks){
            freq[x-'A']++;
        }
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                pq.push(freq[i]);
            }
        }
        int time=0;
        //queue mei dalenge  remaining frequency and next time
        while(!pq.empty() || !q.empty()){
            time++;
            if(!q.empty() && q.front().second==time){
                int frequency=q.front().first;
                q.pop();
                pq.push(frequency);
            }
            if(!pq.empty()){
                int frequency=pq.top();
                pq.pop();
                frequency--;
                if(frequency>0){
                    q.push({frequency,time+n+1});
                }
            }
        }
        return time;
    }
};