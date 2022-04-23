# 231. Power of Two

###### Tag: Math

###### Time: O(1)
###### Time: O(1)


If a positive integer `n` is a power of 2, it must have only 1 set bit at `kth` bit (`0 <= k < 31`). The integer
`n-1` must have all the set bits from `0` to `k-1`. Therefore, the AND operation between `n` and `n-1` is 0.
We could take the advantage of this property to check if a positive integer is power of 2.