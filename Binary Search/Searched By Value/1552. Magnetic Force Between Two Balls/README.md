# 1552. Magnetic Force Between Two Balls

###### Tag: Binary Search, Searched by Value

This is a typical problem using binary search techniques to guess for a solution. In general, if a problem asks for a min value in searching, the template refers to [1482. Minimum Number of Days to Make m Bouquets](https://github.com/zilinli0130/Leetcode_Algorithm/edit/main/Binary%20Search/Searched%20By%20Value/1482.%20Minimum%20Number%20of%20Days%20to%20Make%20m%20Bouquets/README.md).
This problem asks for a max value, the searching template is provided below:

```
int low = 1, high = INT_MAX;
while (low < high) {
  
  int mid = high - (high - low) / 2;
  if (isValid(...)) {
    low = mid;
  } else {
     high = mid - 1; 
  }
}
```
