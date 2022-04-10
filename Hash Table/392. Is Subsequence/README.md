# 392. Is Subsequence

###### Tag: Hash Map

###### Time: O(N)
###### Space : O(N)

Normally, the two pointer approach is able to solve this problem. However, we need to address the follow-up problem: there are 10^9 of `s` string. We could 
establish a hash map to store all the information about `t` string, and define a variable called `nextIdx` = -1. If we find there is existing index in `t` string 
such that `t[idx] = s[i] && idx > nextIdx`, we then update the `nextIdx` and keep the future looping. Otherwise, we can say the `s` is not a subsequence of `t`