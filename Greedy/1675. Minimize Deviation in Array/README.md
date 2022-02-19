# 1675. Minimize Deviation in Array

###### Tag: Greedy, Priority Queue

We could firstly insert all the max potential value for each elements to a `multiset`, the min deviation is the difference between the max and min values inside the current `multiset`. The max value is removed from the `multiset` and its potential next smaller max value is pushed to the `multiset` and the min deviation finding process continues until the potential next smaller max value is not existed.