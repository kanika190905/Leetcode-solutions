class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int num_queries = queries.size();
        vector<pair<int, int>> sorted_queries(num_queries);
        for (int i = 0; i < num_queries; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        
        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> ans(num_queries);
        vector<int> freq(n + 1, 0); 
        int active_servers = 0;     
        int left = 0;  
        int right = 0; 
        for (auto& q : sorted_queries) {
            int q_time = q.first;
            int q_idx = q.second;

            int start_time = q_time - x;
            int end_time = q_time;

            while (right < logs.size() && logs[right][1] <= end_time) {
                int server_id = logs[right][0];
                if (freq[server_id] == 0) {
                    active_servers++; 
                }
                freq[server_id]++;
                right++;
            }

            while (left < logs.size() && logs[left][1] < start_time) {
                int server_id = logs[left][0];
                freq[server_id]--;
                if (freq[server_id] == 0) {
                    active_servers--; 
                }
                left++;
            }

            ans[q_idx] = n - active_servers;
        }

        return ans;
    }
};