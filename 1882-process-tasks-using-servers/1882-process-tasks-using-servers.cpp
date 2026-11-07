#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // idle servers: {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> idle;
        
        // busy servers: {time_free, index}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;

        // Initially, put all servers into idle
        for (int i = 0; i < servers.size(); ++i) {
            idle.push({servers[i], i});
        }

        vector<int> ans(tasks.size());
        long long ts = 0; // current time

        for (int i = 0; i < tasks.size(); ++i) {
            // Task i cannot start before time i
            ts = max(ts, (long long)i);

            // Remove servers satisfying t <= ts from busy and put them into idle
            while (!busy.empty() && busy.top().first <= ts) {
                int idx = busy.top().second;
                busy.pop();
                idle.push({servers[idx], idx});
            }

            // If idle is empty, we must wait for the next server to become free
            if (idle.empty()) {
                ts = busy.top().first;
                
                // Transfer all servers completing by this new timestamp into idle
                while (!busy.empty() && busy.top().first <= ts) {
                    int idx = busy.top().second;
                    busy.pop();
                    idle.push({servers[idx], idx});
                }
            }

            // Pop the server from the front of idle, assign it, and push to busy
            auto [w, idx] = idle.top();
            idle.pop();
            
            ans[i] = idx;
            busy.push({ts + tasks[i], idx});
        }

        return ans;
    }
};