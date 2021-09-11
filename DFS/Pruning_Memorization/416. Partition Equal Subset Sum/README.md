# 416. Partition Equal Subset Sum

###### Tag: DFS, Memorization, Remove Duplicates

This problem can use DFS algorithm to solve for the solution. However, the submission will be TLE without proper pruning tricks. Since the input array might contain duplicated values, let's say there are n number of '2'. We 
only need to visit the 1st '2' and skip the rest of `n - 1` '2's. Since the generated DFS branches for all the '2' are the same. The second trick is memorization, we only need to memorize the failed case by notng down their 
current sum and current index locations. The template for memorization refers to [329. Longest Increasing Path in a Matrix](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/DFS/Pruning_Memorization/329.%20Longest%20Increasing%20Path%20in%20a%20Matrix).
