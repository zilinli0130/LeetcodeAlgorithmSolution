# 1020. Number of Enclaves

###### Tag: BFS

The BFS approach is a good way to solve this problem, we need to loop through all the `1`s on the borders via BFS. At the end, if there are some elements which are not visited, the number of those elements is the answer.