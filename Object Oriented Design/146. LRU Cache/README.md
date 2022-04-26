# 146. LRU Cache
###### Tag: Linked List, Double Linked List, Design

In C++ langauge, we could use `list<int>` which is a double linked list to achieve the LRU cache. If a key is visited, we could move it to the end of list. If the capacity of the 
list is out of range, we could simply erase the first element inside the list, which is guranteed to be the LRU element. 
