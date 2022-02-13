# 1584. Min Cost to Connect All Points

###### Tag: Union Find, MST

## Version 1: Kruskal Algorithm
Time: O(N^2*log(N^2)) -> O(N^2*log(N)) where N^2 is the number of edges (E)

We first need to sort all the edge connections based on the manhattan distance. The edge connection with least manhattan distance so far should be connected (greedy approach) so that the overall manhattan distance would be minimized. In order to avoid connect the edge that has been visited before, we use Union Find to check if a new edge has been connected before or not. 

## Version 2: Prim Algorithm
Time: O(N^2*log(N^2)) -> O(N^2*log(N)) where N^2 is the number of edges (E)
The edge connection with least manhattan distance so far should be connected (greedy approach) so that the overall manhattan distance would be minimized. In order to avoid connect the edge that has been visited before, we use visited array to check if a new edge has been visited before or not. 


