# 692. Top K Frequent Words

###### Tag: Priority Queue, Hash Table

We can use priority queue of size `k` to keep track of the most `k` frequent words while looping throught the entire words array. The time compllexity
would be `O(N*log(K))`. Additionally, we need to store a hash table to record the appeared word and its frequency which costs `O(N)` space.