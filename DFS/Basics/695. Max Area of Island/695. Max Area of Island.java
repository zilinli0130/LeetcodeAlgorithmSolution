class Solution {
    int res = 0;
    int graph[][];
    int dirs[][] = {{0,1},{1,0},{0,-1},{-1,0}};
    public int maxAreaOfIsland(int[][] grid) {
        
        graph = grid;
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[0].length; j++) {
                if (graph[i][j] != 1) continue;
                res = Math.max(res, dfs(i,j));
            }
        }
        return res;
    }
    
    public int dfs(int r, int c) {
        
        int count = 1;
        graph[r][c] = 2;
        for (int k = 0; k < 4; k++) {
            
            int x = r + dirs[k][0];
            int y = c + dirs[k][1];
            if (x < 0 || x >= graph.length || y < 0 || y >= graph[0].length) continue;
            if (graph[x][y] != 1) continue;
            count += dfs(x,y);
        }
        return count;
    }
}