# 1388. Pizza With 3n Slices

###### Tag: Dynamic Programming, Time Sequence

Since we can not take the adjacent slices, it is similar to House Robber II. But one more constraint is that we could only take `k = n/3` slices. Therefore we could define `dp0[i][j]` as the max gain so far by
having `i` total slices and we could take `j` slices but we don't take the current slice,  `dp1[i][j]` as the max gain so far by having `i` total slices and we could take `j` slices but we take the current slice.
Note that `j = min(k,i)`.
