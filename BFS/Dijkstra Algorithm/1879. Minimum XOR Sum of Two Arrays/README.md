# 1879. Minimum XOR Sum of Two Arrays

###### Tag: BFS, Dijkstra Algorithm, Bit Manipulation

This problem could be generalized as finding the min cost to transit `state 000...000` to `state 111...111`. The number of bits `k` in a random state represents there are
`k` numbers in `nums1` have been paired with `nums2[0:k-1]`. Since there are many options to do the pairing, we could use Dijkstra algorithm to find out the min cost among
these options. 
