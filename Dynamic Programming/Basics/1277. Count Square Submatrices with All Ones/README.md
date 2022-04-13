# 1277. Count Square Submatrices with All Ones

###### Tag: Dynamic Programming

###### Time: O(N^2)
###### Space: O(N^2)

Similar to [221. Maximal Square](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/Dynamic%20Programming/Basics/221.%20Maximal%20Square).
If `dp[i][j] = n`, it means that there are n squares with vertice ending at right bottom corner with size of 1,2,3,4,5,...,n.