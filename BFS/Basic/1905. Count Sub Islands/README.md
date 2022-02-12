# 1905. Count Sub Islands

###### Tag: BFS

We could use BFS to find out all the islands in `grid2`. In the mean time, check whether the grid2 island component (`grid2[i][j] == 1`) is euqal to 1 in `grid1`. If not, the current island is not a subset of any islands in `grid1`.