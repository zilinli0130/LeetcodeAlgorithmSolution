# 1590. Make Sum Divisible by P

###### Tag: Prefix Sum, Hash Table

###### Time: O(N)
###### Space: O(N) 

We can use prefix sum to calculate the sub-array sum efficiently. Suppose that we want to remove the interval of `[i,j]`,
It must satisfy that the following condition:

```
totalSum - (prefixSum[j] - prefixSum[i - 1]) = p*n where n is non-negative integer
totalSum % p - (prefixSum[j] - prefixSum[i - 1]) % p = 0
totalSum % p = prefixSum[j] % p - prefixSum[i - 1] % p

Let r0 = totalSum % p, r = prefixSum[j] % p, we need to find prefixSum[i - 1] % p = r - r0
```

We use a hash table to keep track of the index of previously visited `prefixSum[i - 1] % p` (if it exists).
Furthermore, if the `prefixSum[i - 1] % p` is a negative number, we need to take `(prefixSum[i - 1]%p + p) %p`
to replace the original prefix sum instead. 