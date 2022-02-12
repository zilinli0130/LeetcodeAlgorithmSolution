# 1319. Number of Operations to Make Network Connected

###### Tag: Union Find

In order to connect all the computers, we need to make sure that the size of `connections` is not less than `n - 1` where `n` is the number of computers. After that, we could deploy the Union Find algorithm to find out all the unions (`m`). The number of connections that we need to change is `m - 1`. 