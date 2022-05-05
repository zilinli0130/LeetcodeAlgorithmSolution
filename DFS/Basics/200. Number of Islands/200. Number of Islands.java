class Solution {
    char graph[][];
    int dirs[][] = {{0,1},{0,-1},{1,0},{-1,0}};
    public int numIslands(char[][] grid) {
        
        graph = grid;
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != '1') continue;
                dfs(i, j);
                count++;
            }
        }
        return count;
    }
    
    public void dfs(int r, int c) {
        
        for (int k = 0; k < 4; k++) {
            int x = r + dirs[k][0];
            int y = c + dirs[k][1];
            if (x < 0 || x >= graph.length || y < 0 || y >= graph[0].length) continue;
            if (graph[x][y] != '1') continue;
            graph[x][y] = '2';
            dfs(x,y);
        }
    }
}