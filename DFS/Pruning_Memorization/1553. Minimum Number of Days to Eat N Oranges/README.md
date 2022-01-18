# 1553. Minimum Number of Days to Eat N Oranges

###### Tag: DFS, Memorization

We have 3 ways to do the process: -1 or /2 or /3. We can also realize that -1 is not en efficient way if we only use this method all the way from top to bottom. The -1 way is only to reduce n in which n is divisible by either 2 or 3: 
`res = min(num % 2 + 1 + dfs(num/2), num % 3 + 1 + dfs(num/3))`

Since the n is either divided by 2 or 3, the number of levels for the recursion tree is roughly `log(N)`, the total time complexity of this algorithm is `2^0 + 2^1 + 2^2 + ... + 2^(log(N)) = 2^(log(N))`. It is roughly O(N). But the max number of n is `2e9`, but the algorithm does not have the TLE issue since we used the memorization. Supposed that we are at the `kth` level by using `k` times of division(either 2 or 3), we only need to memorize `k + 1` number of possibilities at `kth` level. Therefore, the real time complexity of this algorithm is `1 + 2 + 3 + 4 + ... + logN = (logN)^2`. 