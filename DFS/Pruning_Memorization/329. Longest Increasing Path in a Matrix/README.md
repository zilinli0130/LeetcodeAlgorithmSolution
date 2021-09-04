# 329. Longest Increasing Path in a Matrix

###### Tag: DFS, Memorization
This is a DFS problem to search for longest increasing path inside a 2D matrix. The submission will be TLE if no proper pruning trick is applied. The pruning trick
for this problem is to create memorization for DFS, in other words, using a 2D array (`int memo[200][200]`in C++) to store the longest increasing path at a given row 
and column (e.g. store the longest increasing path starting at `matrix[i][j]` into `memo[i][j]`). The template for memorization is provided below:


```
int memo[200][200];

int dfs(vector<vector<int>>& matrix, int i, int j) {
  
  //This tree branch has been searched before, simply return the cached result
  if (memo[i][j] != 0) {return memo[i][j];}
  
  int result = 0;
  for (...) {
    ...
    result = max(result, 1 + dfs(...));
  }
  
  //Store the result when finishing the searching for current depth
  memo[i][j] = result;
  return result;
}
```
