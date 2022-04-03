# 524. Longest Word in Dictionary through Deleting
###### Tag: Two Pointer

###### Time: O(Nlog(N))
###### Space: O(1) 

Basic two pointer problem. Optimization: we could sort the dictionary array based on the non-increasing length and non-decreasing lexicographical order of each word. If
we find the valid word which satisfies the condition, it will definitely be the answer.
