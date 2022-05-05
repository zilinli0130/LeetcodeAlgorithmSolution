# 547. Number of Provinces

###### Tag: Union Find

###### TIme: O(N^2)
###### Space: O(N)

This is a basic Union Find problem. If the `i` node and `j` node is connected but their ancestor is not the same, we 
need to union them together. Keep in mind that even though `i` node and `j` node shares the same ancestor after the union,
their ancestor might not be the lowest ancestor. For instance, if ancestor of `i` node is `k` node (ancestor of `k` is `k` at this point) 
and the ancestor of `k` node is updated later on, but the update of `k` node's ancestor is not known by `i` node. We need to update the 
ancestor of all nodes again.