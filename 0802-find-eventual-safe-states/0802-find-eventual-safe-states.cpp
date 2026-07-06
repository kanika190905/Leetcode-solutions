class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // Reverse graph
        vector<vector<int>> revGraph(n);

        // indegree in reversed graph = outdegree in original graph
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; u++) {
            indegree[u] = graph[u].size();   // outdegree of original graph

            for (int v : graph[u]) {
                revGraph[v].push_back(u);
            }
        }

        queue<int> q;

        // Push all terminal nodes
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            // Traverse parents in reversed graph
            for (int parent : revGraph[node]) {
                indegree[parent]--;

                if (indegree[parent] == 0)
                    q.push(parent);
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};