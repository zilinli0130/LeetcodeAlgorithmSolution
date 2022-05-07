# 547. Number of Provinces

###### Tag: Union Find

###### TIme: O(N^2)
###### Space: O(N)

This is a basic Union Find problem. If the `i` node and `j` node is connected but their ancestor is not the same, we 
need to union them together. Keep in mind that even though `i` node and `j` node shares the same ancestor after the union,
their ancestor might not be the lowest ancestor. For instance, if ancestor of `i` node is `k` node (ancestor of `k` is `k` at this point) 
and the ancestor of `k` node is updated later on, but the update of `k` node's ancestor is not known by `i` node. We need to update the 
ancestor of all nodes again.


```
DFS Approach:

// Java
class Solution {
    int n;
    int grid[][];
    boolean[] visited;
    public int findCircleNum(int[][] isConnected) {
        
        grid = isConnected;
        n = isConnected.length; 
        visited = new boolean[n];
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            dfs(i);
            count++;
        }
        return count;
    }
    
    private void dfs(int node) {
        
        visited[node] = true;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            if (grid[node][i] == 1) {
                dfs(i);
            }
        }
    }
}
```