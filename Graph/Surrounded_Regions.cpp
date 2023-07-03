class Solution {
public:

    bool boundaryCheck(int row, int col, int n, int m){
        return (row > -1 && col > -1 && row < n && col < m);
    }

    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis){
        if(vis[row][col] == 1 || board[row][col] == 'X') return;

        vis[row][col] = 1;
        
        vector<int> dir_row{-1, 0, 1, 0};
        vector<int> dir_col{0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int new_row = row + dir_row[i];
            int new_col = col + dir_col[i];
            if(boundaryCheck(new_row, new_col, board.size(), board[0].size()))
                dfs(new_row, new_col, board, vis);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && vis[i][0] == 0){
                dfs(i, 0, board, vis);
            }

            if(board[i][m-1] == 'O' && vis[i][m-1] == 0){
                dfs(i, m-1, board, vis);
            }
        }

        for(int i=0; i<m; i++){
            if(board[0][i] == 'O' && vis[0][i] == 0){
                dfs(0, i, board, vis);
            }

            if(board[n-1][i] == 'O' && vis[n-1][i] == 0){
                dfs(n-1, i, board, vis);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};