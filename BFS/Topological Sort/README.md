# Topological Sort

Topological sort is useful when we are dealing with nodes which have pre-requisite requirements for the other nodes in the directed acyclic graph. First, we need to visited
all the nodes with 0 in degree, which means that this node does not have any re-requisite dependency. Using a priority queue to priorize the visiting order of the nodes based 
on the number of in degree for all the nodes.
