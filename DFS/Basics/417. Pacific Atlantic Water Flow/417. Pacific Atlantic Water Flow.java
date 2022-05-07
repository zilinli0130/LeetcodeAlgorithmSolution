class Solution {
    int m, n;
    int grids[][];
    int visitedPac[][];
    int visitedAtl[][];
    int dirs[][] = {{0,1},{0,-1},{-1,0},{1,0}};
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        
        grids = heights;
        m = heights.length;
        n = heights[0].length;
        visitedPac = new int[m][n];
        visitedAtl = new int[m][n];
        
        for (int i = 0; i < m; i++) {
            dfs(visitedPac, i, 0);
        }
        for (int j = 0; j < n; j++) {
            dfs(visitedPac, 0, j);
        }
        for (int i = 0; i < m; i++) {
            dfs(visitedAtl, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(visitedAtl, m - 1, j);
        }
        
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visitedPac[i][j] == 1 && visitedAtl[i][j] == 1) {
                    List<Integer> temp = new ArrayList<>();
                    temp.add(i);
                    temp.add(j);
                    res.add(temp);
                }
            }
        }
        return res;
    }
    
    void dfs(int[][] visited, int r, int c) {
        
        
        visited[r][c] = 1;
        for (int k = 0; k < 4; k++) {
            
            int x = r + dirs[k][0];
            int y = c + dirs[k][1];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (visited[x][y] == 1) continue;
            if (grids[x][y] < grids[r][c]) continue;
            dfs(visited, x, y);
        }
    }
}