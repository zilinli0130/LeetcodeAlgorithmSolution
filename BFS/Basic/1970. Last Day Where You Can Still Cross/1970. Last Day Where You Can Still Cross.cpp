class Solution {
    int row;
    int col;
    vector<pair<int, int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        this->row = row;
        this->col = col;
        int left = 0, right = cells.size() - 1;
        
        while (left < right) {
            
            int mid = right - (right - left) / 2;
            if (checkOK(cells, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left + 1;
    }
    
    bool checkOK(vector<vector<int>>& cells, int mid) {
        
        vector<vector<int>> Graph(row, vector<int>(col, 0));
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i <= mid; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            Graph[r][c] = 1;
        }
        
        queue<pair<int, int>> q;
        for (int j = 0; j < col; j++) {
            if (Graph[0][j] != 1) {
                q.push({0,j});
            }
        }
        
        while (!q.empty()) {
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if (visited[r][c]) continue;
            visited[r][c] = 1;
            
            if (r == row - 1) return true;
            
            for (int k = 0; k < 4; k++) {
                
                int x = directions[k].first;
                int y = directions[k].second;
                if (r + x >= row || r + x < 0 || c + y >= col || c + y < 0) continue;
                if (Graph[r + x][c + y] == 1) continue;
                if (visited[r + x][c + y]) continue;
                q.push({r + x, c + y});
            }
        }
        return false;
    }
};