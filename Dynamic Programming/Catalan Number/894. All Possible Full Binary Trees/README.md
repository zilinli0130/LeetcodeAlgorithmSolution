# 894. All Possible Full Binary Trees

###### Tag: DFS, Catalan Number

###### Time: O(...), bounded by O(2^N)
###### -> see analysis below
###### Space: O(...), bound by O(2^N)
###### -> see analysis below

For even number of nodes, there is no way to construct a basic full binary tree since the size of a completed full binary
tree is either 1 (no child node) or 3 (with left and right child node). We could use DFS to find out all the possible forms
of a fully binary tree: collect all the possible tree nodes on both left and right sides of the current tree node, use nested loop to iterate through all the possible full binary tree combination, then return all the results back to last level
of DFS.

time/space complexity analysis:
Let `Pn` be the number of generated FBT given the input size of `n`. We could easily find out that:

``` 
P1 = 1
P3 = 1
P5 = P1P3 + P3P1 = 2
P7 = P1P5 + P3P3 + P5P1 = 5 
P9 = P1P7 + P3P5 + P5P3 + P7P1 = 16
...

PN = P1P(N-2) + P3P(N-4) + P5P(N-6) + ... + P(N-2)P1 = sum(PkP(N-k-1)) for k = 1,2,...N-2
total number of terms: (N-1)/2
```



 

