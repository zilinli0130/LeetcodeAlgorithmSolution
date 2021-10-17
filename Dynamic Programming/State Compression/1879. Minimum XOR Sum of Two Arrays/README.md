# 1879. Minimum XOR Sum of Two Arrays

###### Tag: Dynamic Programming, State Compression

This problem is a pairing problem which tries to find the min cost (XOR sum) to pair two arrays. We could use a binary number to represent the current state in which k numbers in nums1 have been paired with the nums2[0:k-1]
. For each of the number in nums2, it could be possibly paired with a random number inside nums1 for different states. We need to loop through them to find out the min cost 
as shown below:

```
n = nums1.size(）
for jth element in nums2:
    for state between 0 and (1<<n)：
        for ith bit in state:
            if ith bit is 1:
                dp[state] = min(dp[state], dp[state - (1<<i)] + (nums1[i]^nums2[j]);
```
