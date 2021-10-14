# 805. Split Array With Same Average

###### Tag: Dynamic Programming, Knapsack Problem

This problem asks for determining whether the nums array could be divided into two section and their average sums are the same. In other words, we are trying to
find out if using `num` numbers to form a `sum` in which the average `sum/num` is the same as the total nums array sum divided by array size(`totalSum/n`). Since average vaue
might be floating number, we could transfer this condition into checking whether `totalSum * num == sum * n`. To find out whether this condition is true or not, we need to find out if 
`sum - x` is valid to be constructed from `num - 1` numbers, where `x` is a random element inside the nums array. This is a knapsack problem. The core idea shows below:

```
if (dp[sum - x][num - 1] == 1) {
  dp[sum][num] = 1;
}
```
