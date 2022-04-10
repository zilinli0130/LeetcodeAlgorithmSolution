# 665. Non-decreasing Array

###### Tag: Greedy

###### Time: O(N)
###### Space:O(1)

We need to compare `nums[i - 2]` and `nums[i]`. If `nums[i - 2] <= nums[i]`, we change `nums[i - 1]` to `nums[i]`. Otherwise, we change `nums[i]` to `nums[i - 1]`.
