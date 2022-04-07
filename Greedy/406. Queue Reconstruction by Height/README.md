# 406. Queue Reconstruction by Height
###### Tag: Greedy, Sorting

###### Time: O(Nlog(N))
###### Space: O(1) 

For a random pair of `{h,k}`, it means that there are `k` persons who are taller before itself. Then this pair is on position `k+1` based on the height order before him. We could assume that all the persons who are higher than itself has been placed in the correct location of queue, we could simply insert the current person to the `k` position of the queue. Even though we might insert more shorter persons before the current person afterward, it does not affect the correctness
of `k` value for the current person.