# 464. Can I Win

###### Tag: DFS, Memorization, Game Theory

The problem could be solved by using the DFS algorithm. Given that A will play first, if A make a decision at a random `kth`round bychoosing number `i`, A will definitely win if B would lose given the number set excluding `i` for the next `k+1th` round til the end. The time complexity of this algorithm is `O(N!)` where `N` is the `maxChoosableInteger`. If we use memorization, the time complexity could reduce to `O(2^N)` since we have at most `2^N` states for the DFS.

