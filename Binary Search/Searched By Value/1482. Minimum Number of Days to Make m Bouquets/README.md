# 1482. Mininum Number of Days to Make m Bouquets

###### Tag: Binary Search, Searched By Value

An efficient way to approach this problem is to guess the answer by binary search. The maximum number of times to guess a value is 32. The binary search template is provided below:

```
int low = 1, high = INT_MAX;
while (low < high) {
  int mid = low + (high - low) / 2;
  if (isValid(...)) {
    high = mid; 
    //low = mid
  } else {
    low = mid + 1;
    //high = mid - 1;
  }
  return low;
}
```

Note: This template is only valid when there is always a valid solution to problem.
