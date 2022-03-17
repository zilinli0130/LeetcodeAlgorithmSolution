# 2203. Minimum Weighted Subgraph With the Required Paths

###### Tag: BFS, Dijkstra Algorithm

###### Time: O(V + Elog(E)) ->
###### O(V) to loop through all the vertices to minimize [src1 to node[i] + src2 to node[i] + node[i] to dest], O(Elog(E)) is the standard time for Dijkstra algorithm

###### Space: O(V) ->
###### O(V) to store all the node infos relative to src1, src2 and dest node.

The way to find out the sub graph which has the min cost to have both `src1` and `src2` arrived at `dest` is to loop through all the possible
nodes inside the graph, and find out the min value of `src1 to node[i] + src2 to node[i] + node[i] to dest`. `node[i]` acts like a middle
intersected station for `src1` and `src2`, where `node[i]` could also be either nodes of `src1` and `src2`. 




