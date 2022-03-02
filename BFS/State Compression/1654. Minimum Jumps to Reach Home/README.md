# 1654. Minimum Jumps to Reach Home

###### Tag: BFS, State Compression

Since there is no upper bound for the right move, the program might encounter TLE issue. In order to constrain the right upper bound and make
the final position converging to the desired location `x`, we could set a right upper bound as `max(x, maxForbidden) + b`. If our current position is greater or
euqal than the right upper bound, we should not continue to move on the right side since we might need at least one left move `-b` to approach back to
the desired location `x`.