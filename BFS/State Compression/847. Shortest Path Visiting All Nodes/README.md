# 847. Shortest Path Visiting All Nodes

###### Tag: BFS, State Compression

Since we might need to revisit some nodes in order to visit all the nodes, the elements pushed to queue should be a pair of current node and current state. If the current node and 
current state pair is visited before, we could skip it. 
