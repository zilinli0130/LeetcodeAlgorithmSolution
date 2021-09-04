# 403. Frog Jump

###### Tag: DFS, Memorization, Set

This is a DFS problem. In order to avoid TLE, memorization is necessary to optimize the overall time complexity. The template for memorization refers to [329. Longest Increasing Path in a Matrix](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/DFS/Pruning_Memorization/329.%20Longest%20Increasing%20Path%20in%20a%20Matrix).
The only difference is that 403. only needs to memorize the failed situation (using set to do so), since if a path is successful, it would direcly return true.
