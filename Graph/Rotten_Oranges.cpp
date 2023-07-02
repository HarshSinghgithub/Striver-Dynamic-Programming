    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> qu;
        vector<int> dir_row{-1, 0, 1, 0};
        vector<int> dir_col{0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int level = 0;
        int freshCount = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    qu.push({i, j});
                    vis[i][j] = 1;
                }
                else if(grid[i][j] == 1) freshCount++;
            }
        }
        
        while(!qu.empty()){
            int level_size = qu.size();
            level++;
            
            for(int i=0; i<level_size; i++){
                auto node = qu.front();
                qu.pop();
                
                int row = node.first;
                int col = node.second;
                
                for(int i=0; i<4; i++){
                    int new_row = row + dir_row[i];
                    int new_col = col + dir_col[i];
                    
                    if(new_row < 0 || new_row > n-1 || new_col < 0 || new_col > m-1) continue;
                    
                    if(grid[new_row][new_col] == 1 && vis[new_row][new_col] == 0){
                        qu.push({new_row, new_col});
                        vis[new_row][new_col] = 1;
                        freshCount--;
                    }
                }
            }
        }
        
        return freshCount == 0 ? level-1 : -1;
    }