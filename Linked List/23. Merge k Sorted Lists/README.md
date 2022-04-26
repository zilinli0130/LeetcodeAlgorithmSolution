# 23. Merge k Sorted Lists

###### Tag: Linked List, Priority Queue 

This problem is similar to the idea of BFS with priority queue. We construct the new linked list based on the non-decreasing order of elements insdie the priority queue.

Time Complexity:
Suppose the average length for a list is `N`. Each time, we use a priority queue to pop or insert a new node with a total number of `K` element inside it(`logK`). Therefore, the total time complexity would be `O(N*logK)`. 

Space Complexity:
`O(K)` for the priority queue
`O(N)` for constructing a new linked list
