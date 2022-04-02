# 2216. Minimum Deletions to Make Array Beautiful
###### Tag: Greedy
###### Time: O(N)
###### Space: O(1) 

if we encounter the situation when `i % 2 == 0` and `nums[i] = nums[j], j = i + 1`, we would greedily remove `j` until
`nums[i] != nums[j]` while making sure that `j < nums.size()`. If the `j` is out of bound, we need to remove `i` as well. 