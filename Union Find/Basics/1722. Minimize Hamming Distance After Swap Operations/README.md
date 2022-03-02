# 1722. Minimize Hamming Distance After Swap Operations

###### Tag: Union Find

We can first union all the pairs inside `allowedSwaps ` based on the index values. For each of the union, we can use `multiset<int> Set` to store all the `source` elements inside it. If we found a `target` element from the set, we could eliminate it. At the end, the hamming distance is the number of leftover elements which are not able to be removed.   