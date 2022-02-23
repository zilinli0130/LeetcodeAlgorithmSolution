# 1494. Parallel Courses II

###### Tag: Dynamic Programming, State Compression

This problem can not be solved by topological sort since the decision making to take pre-requisite courses is not easily to generalize. We could use dynamic programming to figure out the optimal solution. For each of the states with `n` bits represented by `n` courses, the course number with bit of `1` means that this course would be included in the current state. The only thing needed to be done is to find out all its associated sub state and determine if thoses sub states meet the course pre-requistes or not. 
