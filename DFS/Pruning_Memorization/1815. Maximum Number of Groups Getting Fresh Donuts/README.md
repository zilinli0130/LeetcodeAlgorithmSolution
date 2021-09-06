# 1815. Maximum Number of Groups Getting Fresh Donuts

###### Tag: DFS, Memorization, Bit Manipulation

This is a DFS problem with memorization. The memorization trick is using bit manipulation to store the result of all the states. The way to do bit manipulaton refers to [638. Shopping Offers](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/DFS/Pruning_Memorization/638.%20Shopping%20Offers).
The core idea of this problem is to figure out the remainder for each groups. If the number of people in any given groups is divisible by donut batch size, it is a happy group. If the sum of remainders from several groups can be divisible by dounut batch size, then there is exisiting a happy group among those groups.
