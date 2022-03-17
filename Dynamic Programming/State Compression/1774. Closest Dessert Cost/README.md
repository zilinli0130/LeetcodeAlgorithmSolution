# 1774. Closest Dessert Cost

###### Tag: Dynamic Programming, State Compression

###### Time: O(N*3^M*M)
###### O(N) -> number of bases, O(3^M) -> number of topping choices, O(M) -> calculate the total cost (m bits)

###### Space: O(1)

We could use the trinary bit idea to represent the states of topping selection (3^M of choices). To get the number of last bit, take the `%3` operation.
To reduce the last bit, take the `/3` operation.