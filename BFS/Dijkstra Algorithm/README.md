# Dijkstra Algorithm

The Dijkstra algorithm is an optimal way to find out the shortest path between start and end points with the least cost. This algorithm is basically the same as BFS except
it uses a priority queue to keep track of the next nodes. We usually store 3 variables into the priority queue: the row, column index and cost to reach the next node. The
structure of the priority queue shows below:

```
typedef vector<int> VI;
priority_queue<VI, vector<VI>, greater<>> pq;
```
