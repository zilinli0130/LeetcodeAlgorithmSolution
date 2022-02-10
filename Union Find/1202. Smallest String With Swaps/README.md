# 1202. Smallest String With Swaps

###### Tag: Union Find

We can first union all the pairs inside `pairs  ` based on the index values. For each of the union, we can use hashmap to find out all the indexes for a random union. We sort the substring inside the union and update the string locally. 