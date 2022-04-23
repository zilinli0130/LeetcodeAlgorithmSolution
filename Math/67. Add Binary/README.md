# 67. Add Binary

###### Tag: Math, Two Pointer

###### Time: O(N)
###### Space: O(1)

We define a variable called `carry` to store the current number of `1` bit. The current bit of the resultant string would be `carry % 2`. To update the carry, 
it would be `carry /= 2`.