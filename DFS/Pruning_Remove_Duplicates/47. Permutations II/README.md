# 47. Permutations II

###### Tag: DFS, Optimization
This problem is the extension of [46. Permuations](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/DFS/Basic/46.%20Permutations), the only difference is that the input array contains duplicate values. In order to prune the DFS tree branch, a helper value `int lastNum = -11` is introduced to keep track of last visited element on the current DFS tree branch depth. If the current element has been seen before, it is valid to skip it since it would produce the same branch as the last visited element had in the future. The pseudo code to skip duplicates is provided:


```
//Sort the input array so that the elements with same values would place together
sort(nums.begin(), nums.end());

void dfs(...) {

  //Return condition
  if (...) {return;}
  
  int lastNum = -11;
  for (int i = 0; i < nums.size(); i++) {
  
    //Skip the duplicates
    if (lastNum == nums[i]) continue;
    lastNum = nums[i];
    ...
    dfs(...);
    ...
  }
}
```
