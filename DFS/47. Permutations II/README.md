47. Permutations II

This problem is the extension of 46. Permutation. The key difference between them is that 47. includes duplicate elements inside the given input array. 
The way to prune DFS branches is to skip duplicate elements by keeping track of the last visited element on the current depth of DFS. If the last visited
element is the same as the current element, it is legit to skip it.


`void dfs() {`
  `if () {`
    `return;`
  }`
  
  `int lastNum = INT_MIN;`
  `for (int i = 0; i < nums.size(); i++) {`
    `if (nums[i] == lastNum) continue;`
    `dfs()`
  `}`
`}`
