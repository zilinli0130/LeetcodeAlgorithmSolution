# 142. Linked List Cycle II
###### Tag: Linked List, Two Pointer

###### Time: O(N)
###### Space: O(1) 

```
A_______________B________C
                |        |
                |        |
                |        |
              D | _______| E

AB = m, BC = p, BCDE = n

Supose that fast and slow pointers meet at point C, the speed of fast pointer is twice as the slow pointer

distance traveled by fast pointer = (m + k1*n + p)
distance traveled by slow pointer = (m + k2*n + p)

(m + k1*n + p) = 2 * (m + k2*n + p)
(k1-2k2)*n = p + m

since p + m > 0, k1-2k2 > 0
let p + m = k3*n where k3 = k1 - 2*k2

we could realize that the displacement (not total traveled distance) of m = n - p = BCDE

since AB = m = BCDE, we could use two pointer to move forward until they meet each other at point B (entry of circle)
```
