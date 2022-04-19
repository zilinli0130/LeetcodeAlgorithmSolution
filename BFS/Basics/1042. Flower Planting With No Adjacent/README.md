# 1042. Flower Planting With No Adjacent

###### Tag: BFS, Greedy

###### Time: O(N)
###### Space: O(1)

Since there are at most three edges coming in or out to a random node, there must be a valid color selection for the random node. We could
loop through all the nodes, if the node is colored,  simply skip it. Otherwise, we need to check the color for all its neighbor nodes. A convenient 
way is to use a set keep track of all the invalid colors (color of all its neighbor nodes) for the current node. If we find a color which is not inside
the set, we assign this color to the current node.