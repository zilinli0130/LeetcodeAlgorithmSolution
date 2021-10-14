# 688. Knight Probability in Chessboard

###### Tag: Dynamic Programming, Time Sequence

Since the max number of move for the knight is k times, this is a recursive problem in which the current state depends on the next state. We can realize that only the
kth state of this problem is deterministic, since we can move k times. The trick is to first calculate the probability that the Knight would stay in board for all the
grids at kth time. The Knight can move toward 8 directions, the probability of staying in board at kth move is either 1 (stay in board) or 0 (out of board), Thus the probability
for knight to start move at a random grid`[i][j]` at kth time is `P = 1/8*(probability of staying in boardin 8 directions)`. Once we figure out the probability at kth move, we
can iterate back from k-1th to the 1st time move. 
