# 342. Power of Four

###### Tag: Math

###### Time: O(1)
###### Space: O(1)

If a number is the power of four, it must be a power of two as well. So we can reuse the idea from [231. Power of Two](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/Math/231.%20Power%20of%20Two). Next step, we need to check if the integer is power of 4 by the following math idea:


```
power of 4 : 2^(2k) for k = 0,1,2,3...
power of 2 : 2^(2k+1) for k = 0,1,2,3,...

2^(2k) = 4^k = (1+3)^k
(1+3)^k % 3 = 1

2^(2k + 1) = 2 * 2^(2k) = 2 * (1+3)^k
2 * (1+3)^k % 3 = 2

Therefore, if a number is power of 4, the remainder of this number after being divided by 3 is 1.
```