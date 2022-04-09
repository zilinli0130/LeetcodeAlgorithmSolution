# 523. Continuous Subarray Sum

###### Tag: Prefix Sum, Hash Table, Mod

```
prefixSum[i - 1] + sum(i,j) = prefixSum[j]
prefixSum[i - 1] % k + sum(i,j) % k = prefixSum[j] % k
prefixSum[i - 1] % k = prefixSum[j] % k

```

we need to find whether the value of current prefix sum mod k has been found before and its length between those two indexs is greater than 2.