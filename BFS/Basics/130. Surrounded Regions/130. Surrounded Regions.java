class Solution {
    public void solve(char[][] board) {
        
        int m = board.length;
        int n = board[0].length;
        int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        Queue<Pair<Integer,Integer>> q = new LinkedList<>();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.add(new Pair<>(i, 0));
            }    
        }
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') {
                q.add(new Pair<>(i, n - 1));
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O') {
                q.add(new Pair<>(0, j));
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[m - 1][j] == 'O') {
                q.add(new Pair<>(m - 1, j));
            }
        }
        
        while (!q.isEmpty()) {
            
            int len = q.size();
            while (len-- > 0) {
                
                Pair<Integer,Integer> pairInfo = q.poll();
                int i = pairInfo.getKey();
                int j = pairInfo.getValue();
                
                if (board[i][j] == 'A') continue;
                board[i][j] = 'A';
                
                for (int k = 0; k < 4; k++) {
                    int x = i + dirs[k][0];
                    int y = j + dirs[k][1];
                    if (x < 0 || x >= m || y < 0|| y >= n) continue;
                    if (board[x][y] == 'A') continue;
                    if (board[x][y] == 'X') continue;
                    q.add(new Pair<>(x,y));
                }
            }
        } 
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
}