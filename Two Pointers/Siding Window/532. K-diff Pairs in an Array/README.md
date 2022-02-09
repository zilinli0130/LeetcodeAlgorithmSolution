# 532. K-diff Pairs in an Array
###### Tag: Two Pointers, Sliding Window

This problem addresses the two pointer method. We initialize two pointers `i` and `j` at first, if the diff between them is less than `k`, we move `j` pointer to the right to increase the diff; If the diff is exactly `k`, we move both pointers together to the right. Make sure to skip all the duplicates element at this case. If the diff is greater than `k`, we move the `i` pointer to the right to reduce the diff.