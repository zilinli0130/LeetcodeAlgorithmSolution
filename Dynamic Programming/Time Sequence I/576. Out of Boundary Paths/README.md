# 576. Out of Boundary Paths

###### Tag: Dynamic Programming, Time Sequence

This problem could be intepreted in a reverse way: How many paths can the ball move to the desired location from out of boundary places? Imagining we have a 2x2 square as shown
below:

```
  X X
X 0 0 X
X 0 0 X
  X X
``` 

`X` represents the out of boundary locations. Suppose we are at location `[i][j]`, the max move is N. Then the number of paths that the ball can move to `[i][j]` is the 
sum of the number of paths from locations `[i - 1][j], [i + 1][j], [i][j - 1], [i][j + 1]`. If any of those locations is out of boundary, then the number of paths from this 
location to `[i][j]` is 1 only.
