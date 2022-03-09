# 659. Split Array into Consecutive Subsequences

###### Tag: Greedy, Hash Table

We can use a hash table to record the number of any sequences with a specific ending number. For any given number `num`, we need to check if the sequence 
with ending number of `num-1` exists or not. If it exists, we can append `num` into this exsiting sequence greedily (Because we are not sure whether at least `num+1` and `num+2` exist in the next few positions, appending the `num` to exisitg sequence is a safer way) and update the sequence hash map. Otherwise, we need to 
create a new sequence and check if `num+1` and `num+2` exist. If either of them is not existing, we are not able to at least construct a new valid 
sequence wtih starting element of `num` and ending element of `num+2`.     