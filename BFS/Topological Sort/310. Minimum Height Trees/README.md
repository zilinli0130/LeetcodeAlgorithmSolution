# 310. Minimum Height Trees

###### Tag: BFS, Topological Sort

Topological sort can firstly find out all the nodes which have degree of 1, they are all exposed on the outside of the entire tree structure. We then use BFS to reduce the degrees for desired nodes and terminate til there only one or two nodes left.  