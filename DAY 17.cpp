// Surrounded Regions

class Solution {
public:
    
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& safe) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || safe[x][y] || board[x][y] == 'X')
            return;
        safe[x][y] = true;
        dfs(x + 1, y, board, safe), dfs(x, y + 1, board, safe), dfs(x, y - 1, board, safe), dfs(x - 1, y, board, safe);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(!m)
            return;
        int n = board[0].size();
        
        vector<vector<bool>> safe(m, vector<bool>(n, 0));
        
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0, board, safe);
            }
            if(board[i][n - 1] == 'O') {
                dfs(i, n - 1, board, safe);
            }
        }
        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') {
                dfs(0, i, board, safe);
            }
            if(board[m - 1][i] == 'O') {
                dfs(m - 1, i, board, safe);
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!safe[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};