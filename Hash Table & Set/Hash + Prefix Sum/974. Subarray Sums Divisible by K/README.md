# 974. Subarray Sums Divisible by K

###### Tag: Prefix Sum, Hash Table

###### Time: O(N)
###### Space: O(N) 

We could use the prefix sum to find the sum of an arbitary sub-array with more efficiency. Imaging the sume of 
sub-array `[i,j]` is divisible by `k`, it must satisfies the following condition:

'''
prefixSum[j] - prefixSum[i - 1] = k*n where n is non-nagative integer
prefixSum[j]%k - prefixSum[i - 1]%k = (k*n)%k
prefixSum[j]%k - prefixSum[i - 1]%k = 0
'''

We can conclude from the above expression that if we have found a same remainder value of the current prefix sum previously, there must be at least one sub-array satisfying that its sum is divisible by `k`. One thing to keep in
mind is that if the prefix sum value is less than 0, we need to take `(prefixSum%k + k)%k` as the remainder instead. 