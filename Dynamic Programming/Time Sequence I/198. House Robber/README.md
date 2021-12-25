# 198. House Robber

###### Tag: Dynamic Programming, Time Sequence

We can define two states: `0` representing not robbing and `1` representing robbing. If we rob the `ith` house, we should not rob the `(i-1)th` house in order to not activate the alarm. If we do not rob the `ith`
house, then the max profit at `ith` house is the max profit from `(i-1)th` house.
