# 326. Power of Three

###### Tag: Math

###### Time: O(1)
###### Space: O(1)


Since the input data type it `int` which is a 4 bytes data type (32-bit signed integer by default). The range of `int`
is `[-2^32, 2^31 - 1]`, with total number of `2^32` integers. The upper bound of positive `3^x` falls inside the range
of `(0, 2^31 - 1]` is `3^(log(3, 2^31-1)) = 3^19.56`, which is `3^19`. All the possible `3^x` such as `3^0, 3^1, 3^2,..`
are divisors of `3^19`. If `3^19` is divisible by `n`, it means that `n` must be one of the divisors `3^x` for `x in [0,19]`.


```
Naive Approach:

Use 3 to divide `n` iteratively until `n % 3 != 0`. The time complexity is log(3,n) and space complexity is O(1)
```