class Solution {
public:

    bool boundaryCheck(int row, int col, int n, int m){
        return (row > -1 && row < n && col > -1 && col < m);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> dir_row{-1, 0, 1, 0};
        vector<int> dir_col{0, 1, 0, -1};
        vector<vector<int>> res(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> qu;
        int level = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    qu.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!qu.empty()){
            int level_size = qu.size();
            level++;

            for(int i=0; i<level_size; i++){
                auto node = qu.front();
                qu.pop();

                int curr_row = node.first;
                int curr_col = node.second;

                res[curr_row][curr_col] = level-1;

                for(int i=0; i<4; i++){
                    int next_row = curr_row + dir_row[i];
                    int next_col = curr_col + dir_col[i];

                    if(boundaryCheck(next_row, next_col, n, m) && vis[next_row][next_col] == 0){
                       qu.push({next_row, next_col});
                       vis[next_row][next_col] = 1;
                    }
                }
            }
        }

        return res;
    }
};