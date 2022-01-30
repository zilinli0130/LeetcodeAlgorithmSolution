# 2127. Maximum Employees to Be Invited to a Meeting

###### Tag: BFS, Topological Sort

We can use topological sort to remove all the nodes with in degree of 1, the remaining nodes would form multiple unconnected circles
(`size >= 3` or `size = 2`). For the case of `size >= 3`, we call it poly-circle. The poly-circles are not able to be unioned together to
form a circle with bigger size. Therefore, we find the poly-circle with the max size. On the other hand, we call it binary-circle for case of `size = 2`. Since there are only two nodes, it is possible to add more acyclic node link to both sides of the binary-circle to form a bigger circle. We just need to find the node link connected to the sides of binary-circle with the max depth. Finally, we compare the size between poly-circle and binary-circle to determine the answer. 