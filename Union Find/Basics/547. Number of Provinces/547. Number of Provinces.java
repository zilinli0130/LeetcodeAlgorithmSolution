class Solution {
    int Ancestor[];
    public int findCircleNum(int[][] isConnected) {
        
        int n = isConnected.length;
        Ancestor = new int[n];
        for (int i = 0; i < n; i++) {
            Ancestor[i] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isConnected[i][j] == 1 && FindAncestor(i) != FindAncestor(j)) {
                    Union(i,j);
                }
            }
        }
        
        Set<Integer> hashSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            Ancestor[i] = FindAncestor(i);
            hashSet.add(Ancestor[i]);
        }
        return hashSet.size();
    }
    
    private int FindAncestor(int x) {
        
        if (Ancestor[x] != x) {
            Ancestor[x] = FindAncestor(Ancestor[x]);
        }
        return Ancestor[x];
    }
    
    private void Union(int x, int y) {
        
        x = Ancestor[x];
        y = Ancestor[y];
        if (x <= y) {
            Ancestor[y] = x;
        } else {
            Ancestor[x] = y;
        }
    }
}