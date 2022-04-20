# 172. Factorial Trailing Zeroes

###### Tag: Math

###### Time: O(log(5,n))
###### Space: O(1)

The number of trailing zeroes is exactly the same as the number of 10 in `N!`. Since `10=2x5`, we can guarantee to find a `2` before `5`, the problem is transformed into finding how many 5s from the range `[1,N]`. The number of 5s inside `[1,N]` is the sum of 
`N/5 + N/5^2 + N/5^3+...N/5^k` where `5^k <= N, k <= log(5,N)`. 
`N/5` means the number of 5s contributed from the multiples of 5 such as 5,10,15...
`N/5^2` means the number of 5s contributed fromthe multiples of 5^2 such as 25,50,75... 

```
Example: N=42
integer that is less than or equal to 42 has factor of 5:
5,10,15,20,25,30,35,40

number of 5s contributed from the multiples of 5: 5,10,15,20,25,30,35,40
number of 5s contributed from the multiples of 5^2: 25
number of 5s contributed from the multiples of 5^3: N/A

total number of factorial trailing zeroes of 42: 9
```

