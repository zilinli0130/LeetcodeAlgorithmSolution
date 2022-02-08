# 424. Longest Repeating Character Replacement
###### Tag: Two Pointers, Sliding Window

For a given interval `[i,j]`, if difference between the length of this interval `j - i + 1` and the max frequency of same element inside this interval is less than or equal to `k`, we could move the `j` pointer forward to find a bigger interval. Otherwise, we need to update the `i` pointer one step toward the right direction to find the next potential interval. 