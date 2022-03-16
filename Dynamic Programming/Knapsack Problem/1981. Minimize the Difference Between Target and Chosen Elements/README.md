# 1981. Minimize the Difference Between Target and Chosen Elements

###### Tag: Dynamic Programming, Hash Set, Knapsack Problem

Since there might be duplicated results of the current sum on each row, we could use a set to record all the visited sum. It would make sure
that the time complexity to iterate each row would not exceed `O(capacity of set @ row i * number of column)`. There is another optimization on the 
`capacity of set @ row i`: if we somehow encounter some current sums which are greater than the target, we could just record the min sum which 
is greater than the target, since the rest of sum candidates would have a much larger absolute difference w.r.t target than the min sum. Thus,
we could optimize the total time complexity to `O(number of row * capacity with min absolute difference with target * number of column)`