# 287. Find the Duplicate Number

###### Tag: Bninary Search, Searched by Value

Since the range of values is [1,n] and there are n + 1 elements. It ensures that there must be at least one duplicate value. Suppose we are at a random range of [1,k], if range 
[1,k] does not contain duplicates, the number in which less than or equal to k is k. If [1,k] contains duplicates, the number in which less than or equal to k must be greater than k, no matter
whether there is missing number or not inside the range[1,k].
