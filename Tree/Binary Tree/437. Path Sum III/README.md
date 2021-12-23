# 437. Path Sum III

###### Tag: Binary Tree, DFS

Since the path sum is not necessary starting from the root node, we could use prefix sum idea to find the path sum in any location as long
as the path is continuous. A map is used to store all the visited pfefix sum, when we reach a new node, we can check if the difference of 
current prefix sum and target is inside the map or not. If so, we find `Map[prefixSum - target]` number of valid paths at current node.