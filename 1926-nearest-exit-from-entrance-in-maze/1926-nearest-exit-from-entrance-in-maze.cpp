class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();

        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0], entrance[1]}, 0});

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[entrance[0]][entrance[1]] = 1;

        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int dist = curr.second;

            if((r == 0 || c == 0 || r == m-1 || c == n-1) &&
               !(r == entrance[0] && c == entrance[1])) {
                return dist;
            }

            for(int k = 0; k < 4; k++) {
                int nr = r + delr[k];
                int nc = c + delc[k];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                   maze[nr][nc] == '.' && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }

        return -1;
    }
};