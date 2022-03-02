# 1391. Check if There is a Valid Path in a Grid

###### Tag: BFS, Basic

The BFS algorithm is an optimal way to solve this problem. We need to make sure that what are the valid next street connections w.r.t current street. In order to check whether it is valid to walk from street m to street n, the street direction is bi-directional, we could check if we can get back to street m when we are at street n. If so, the connection is valid, we can continue the exploration.
