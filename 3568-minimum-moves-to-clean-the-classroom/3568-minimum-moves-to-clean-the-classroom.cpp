class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        // Queue now stores: {row, col, energy_left, moves, mask}
        queue<tuple<int, int, int, int, int>> q;
        int n = classroom.size(), mm = classroom[0].size();
        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, -1, 0, 1};
        vector<pair<int, int>> litter;
        int k = 0;
        
        int start_r = -1, start_c = -1;

        // 1. Locate start and all litters
        for(int i = 0; i < n; i++){
            for(int j = 0; j < mm; j++){
                if(classroom[i][j] == 'S'){
                    start_r = i;
                    start_c = j;
                }
                if(classroom[i][j] == 'L'){
                    bool flag = false;
                    litter.push_back({i, j});
                    k++;
                    for(int t = 0; t < 4; t++){
                        int nr = delr[t] + i;
                        int nc = delc[t] + j;
                        if(nr >= 0 && nc >= 0 && nr < n && nc < mm && classroom[nr][nc] != 'X' ){
                            flag = true;
                        }
                    }
                    if(!flag) return -1; // Completely blocked litter
                }
            }
        }

        // 2. Visited array to prevent infinite loops. 
        // vis[row][col][mask] = max_energy_left
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(mm, vector<int>(1 << k, -1)));

        // 3. Initialize queue
        q.push({start_r, start_c, energy, 0, 0});
        vis[start_r][start_c][0] = energy;
        int target_mask = (1 << k) - 1;

        // 4. BFS
        while(!q.empty()){
            auto [row, col, e, m, mask] = q.front();
            q.pop();

            // If we have collected all litters, we are done
            if(mask == target_mask) return m;
            if(e == 0) continue;
            
            for(int t = 0; t < 4; t++){
                int nr = delr[t] + row;
                int nc = delc[t] + col;
                
                if(nr >= 0 && nc >= 0 && nr < n && nc < mm && classroom[nr][nc] != 'X'){
                    int next_e = e - 1;
                    int next_mask = mask;

                    // Handle Energy Refill
                    if(classroom[nr][nc] == 'R'){
                        next_e = energy; 
                    }

                    if(next_e >= 0){
                        // Handle Litter Collection
                        if(classroom[nr][nc] == 'L'){
                            // Find which litter this is in the vector and set its bit
                            for(int i = 0; i < k; i++){
                                if(litter[i].first == nr && litter[i].second == nc){
                                    next_mask |= (1 << i);
                                    break;
                                }
                            }
                        }

                        // Only push if we haven't been here with THIS mask and equal/better energy
                        if(vis[nr][nc][next_mask] < next_e){
                            vis[nr][nc][next_mask] = next_e;
                            q.push({nr, nc, next_e, m + 1, next_mask});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};