class Solution {
    int m, n;
    vector<vector<int>> visited;
    vector<pair<int, int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    void solve(vector<vector<char>>& board) {
        
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<int>(n,0));
        
        //1st Col
        for (int i = 0; i < m; i++) {
            if (visited[i][0]) continue;
            if (board[i][0] == 'X') continue;
            visited[i][0] = 1;
            board[i][0] = '*';
            dfs(board, i, 0);
        }
        //last Col
        for (int i = 0; i < m; i++) {
            if (visited[i][n - 1]) continue;
            if (board[i][n - 1] == 'X') continue;
            visited[i][n - 1] = 1;
            board[i][n - 1] = '*';
            dfs(board, i, n - 1);
        }
        //1st Row
        for (int j = 0; j < n; j++) {
            if (visited[0][j]) continue;
            if (board[0][j] == 'X') continue;
            visited[0][j] = 1;
            board[0][j] = '*';
            dfs(board, 0, j);
        }
        //last Row
        for (int j = 0; j < n; j++) {
            if (visited[m - 1][j]) continue;
            if (board[m - 1][j] == 'X') continue;
            visited[m - 1][j] = 1;
            board[m - 1][j] = '*';
            dfs(board, m - 1, j);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '*') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
    
    
    void dfs(vector<vector<char>> &board, int i, int j) {
           
        for (int k = 0; k < 4; k++) {
            int x = i + directions[k].first;
            int y = j + directions[k].second;
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (board[x][y] == 'X') continue;
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            board[x][y] = '*';
            dfs(board, x, y);
        }
    }
};