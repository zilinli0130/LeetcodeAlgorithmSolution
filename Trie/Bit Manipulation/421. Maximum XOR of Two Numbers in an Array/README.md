# 421. Maximum XOR of Two Numbers in an Array

###### Tag: Trie, Bit Manipulation
The way to solve this problem in linear time is to construct a trie which contains the bit information for all the numebr inside the array. If we are given a random number, the target to get
the maximum XOR with this number is that the target should have the opposite bit value w.r.t the number on every bit ideally. We use the Trie to search for such target in linear
time.

Trie construction refers to:
[208. Implement Trie (Prefix Tree)](https://github.com/zilinli0130/Leetcode_Algorithm/tree/main/Trie/208.%20Implement%20Trie%20(Prefix%20Tree)).

