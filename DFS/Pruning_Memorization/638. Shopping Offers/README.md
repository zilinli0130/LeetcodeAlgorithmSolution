# 638. Shopping Offers

###### Tag: DFS, Memorization, Bit Manipulation
This is a DFS problem by using memorization to prune DFS tree branches. Memorization template can refer to [329. Longest Increasing Path in a Matrix](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/DFS/Pruning_Memorization/329.%20Longest%20Increasing%20Path%20in%20a%20Matrix).
The only difference is that 638. should use bit manipulation to represent the memorization state. Suppose there are k number of items, the maximum value for each item is n, where 0<=n<=2^m-1. Therefore a state could use kxm number of bits to represent.
See details below:

```
          m bits    m bits    m bits           m bits    k items
state = XXX...XXX XXX...XXX XXX...XXX ...... XXX...XXX   k*m bits

Add value to ith item inside the state: state += needs[i]<<(i*m), 0<=i<k
Read value on ith item inside the state : (state>>(i*m) % 2^m),   0<=i<k

```
