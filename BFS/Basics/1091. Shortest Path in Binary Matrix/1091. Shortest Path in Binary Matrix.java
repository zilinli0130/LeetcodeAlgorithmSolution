class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        
        // a node is visited -> grid[i][j] = 2
        int pathLength = 0;
        int m = grid.length, n = grid[0].length;
        int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        if (grid[0][0] == 0) {
            queue.add(new Pair<>(0,0));
        }
        
        while (!queue.isEmpty()) {
            
            int len = queue.size();
            pathLength++;
            while (len-- > 0) {
                
                Pair<Integer,Integer> nodeInfo = queue.poll();
                int r = nodeInfo.getKey();
                int c = nodeInfo.getValue();
                
                if (grid[r][c] == 2) {
                    continue;
                }
                grid[r][c] = 2;
                
                if (r == m - 1 && c == n - 1) {
                    return pathLength;
                }
                
                for (int k = 0; k < 8; k++) {
                    
                    int x = r + dirs[k][0];
                    int y = c + dirs[k][1];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    if (grid[x][y] == 1 || grid[x][y] == 2) {
                        continue;
                    } 
                    queue.add(new Pair<>(x,y));
                }
            }
        }
        return -1;
    }
}