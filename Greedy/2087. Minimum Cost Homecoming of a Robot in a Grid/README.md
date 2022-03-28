# 2087. Minimum Cost Homecoming of a Robot in a Grid

###### Tag: Greedy

If we use Dijkstra' algorithm to find out the path of min cost, the time complexity would be `O(N^2)` where `N` is the size of row or column. It would cause the TLE issue based on the given input size. We could think of this problem in the other way, the total row steps would be the absolute difference between start and home row and the column steps would be the absolute difference between the start and home column as well since there are not obstacles inside the grid. If we traverse somewhere outside the rectangular range defined by the start and home vertices, it would incure more costs to find an optimal path.