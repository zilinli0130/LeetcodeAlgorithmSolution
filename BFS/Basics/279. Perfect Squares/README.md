# 279. Perfect Squares

###### Tag: BFS

###### Time: O(N), O(sqrt(N)) for listing all square numbers, O(N) for searching the result
###### Space: O(N)

We could think of this problem as the graph traversal: find the shortest path from 0 to `n` such that all the nodes on the path are square numbers. In order to know the possible square numbers inside the range of `[0,n]`, we could find out all the square numbers inside this range by a `O(sqrt(N))` fo loop. Next, it is the basic BFS traversal problem to find out the shortest path.

```
Naive Approach: Dynamic Programming
Time: O(N^2)
Space: O(N)

class Solution {
    public int numSquares(int n) {
        
        int[] dp = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            if (Math.sqrt(i) % 1 == 0) {
                dp[i] = 1;
                continue;
            }
            dp[i] = Integer.MAX_VALUE;
        }
        dp[1] = 1;
                
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i/2; j++) {
                dp[i] = Math.min(dp[i], dp[j] + dp[i - j]);
            }
        }
        return dp[n];
    }
}

```