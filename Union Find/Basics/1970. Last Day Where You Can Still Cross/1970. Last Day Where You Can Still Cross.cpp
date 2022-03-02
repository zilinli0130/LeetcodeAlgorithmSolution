class Solution {
    vector<int> Ancestor;
    vector<vector<int>> Graph;
    vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        Ancestor.resize(row * col + 2);
        Graph.resize(row, vector<int>(col, 0));        
        for (int i = 0; i < row * col + 2; i++) {
            Ancestor[i] = i;
        }
        
        for (int i = 0; i < cells.size(); i++) {
            Graph[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                
                if (Graph[i][j] == 1) continue;
                for (int k = 0; k < 4; k++) {

                    int x = i + directions[k].first;
                    int y = j + directions[k].second;
                    if(x >= row || x < 0 || y >= col || y < 0) continue;
                    if (Graph[x][y] == 1) continue;
                    
                    if (FindAncestor(i * col + j) != FindAncestor(x * col + y)) {
                        Union(i * col + j, x * col + y);
                    }
                }
            }
        }
        
        //Union the top dummy with the first row
        for (int j = 0; j < col; j++) {
            Union(row * col , 0 * col + j);
        }
        
        //Union the bottom dummy with the last row
        for (int j = 0; j < col; j++) {
            Union(row * col + 1, (row - 1) * col + j);
        }        
        
        
        for (int t = cells.size() - 1; t >= 0; t--) {
            
            if (FindAncestor(row * col) == FindAncestor(row * col + 1)) return t + 1;
            
            int i = cells[t][0] - 1;
            int j = cells[t][1] - 1;
            Graph[i][j] = 0;
            
            for (int k = 0; k < 4; k++) {

                int x = i + directions[k].first;
                int y = j + directions[k].second;
                if(x >= row || x < 0 || y >= col || y < 0) continue;
                if (Graph[x][y] == 1) continue;

                if (FindAncestor(i * col + j) != FindAncestor(x * col + y)) {
                    Union(i * col + j, x * col + y);
                }
            }
        }
        return 0;
    }
    
    int FindAncestor(int x) {
        
        if (Ancestor[x] != x) {
            Ancestor[x] = FindAncestor(Ancestor[x]);
        }
        return Ancestor[x];
    }
    
    void Union (int x, int y) {
        
        x = Ancestor[x];
        y = Ancestor[y];
        if (x <= y) {
            Ancestor[y] = x;
        } else {
            Ancestor[x] = y;
        }
    }
    
    
};