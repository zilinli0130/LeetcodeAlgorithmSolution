# 138. Copy List with Random Pointer

##### Tag: Linked List, DFS, Hash Table

We can use DFS to copy the a new list. In order to keep track of the random relationship between each nodes, we could
use a hash table tp map the head linked list and the copied linked list at a specific index:

```

Map[head] = ptr;
...//ptr construction
ptr->random = Map[head->randomw] //Get the actual part of ptr by calling Map[head->random]
```