# 904. Fruit Into Baskets

###### Tag: Sliding Window, Hash Table

We could construct a has table to keep track of the number of each fruit types and use the twp pointer method to construct a sliding window for traversing (left pointer remains stable and the right pointer moves forward until the size of hash table is greater than 2 since we only have 2 baskets). We then throw away the fruits until the
size of hash table is back to 2 which means that we are valid to continue for traversing the future fruit types. One optimization is to check whether the number of remaining fruits are less than or equal to our current max stored result, if so, we don't need to traverse the rest of fruits anymore.