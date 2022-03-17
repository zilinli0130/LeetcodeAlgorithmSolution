# Dijkstra Algorithm

The Dijkstra algorithm is an optimal way to find out the shortest path between start and end points with the least cost. This algorithm is basically the same as BFS except
it uses a priority queue (min heap) to keep track of the next nodes. We usually store 3 variables into the priority queue: the row, column index and cost to reach the next node. The structure of the priority queue shows below:

```
typedef vector<int> VI;
priority_queue<VI, vector<VI>, greater<>> pq;
```

Complexity Analysis:
TIme: O(V + Elog(E))
Space: O(V)

```
// Assuming the adjacency list is provided, otherwise we need to consider the time complexity to construct the adjacency list as well
// Initialize a vector to check if a vertice has been visited or not
//Space: O(V)
vector<int> visited(V,0) 

queue<pair<int,int>> pq;

while (!pq.empty())
{
    auto nodeInfo = pq.top();
    pq.pop(); //Time: O(E), we have `E` number of edges in worst case

    //Time: O(Elog(E))
    for (auto next: Adjacency List[curNode])
    //Time: O(E), we have `E` number of edges in the worst case for a single vertice
    {
        //Time: O(logE), we have `E` number of edges inside the min heap for the worst case
        pq.push(next);

    }
}
```
