# 316. Remove Duplicate Letters

###### Tag: Greedy, Monotonic Stack

###### Time: O(N)
###### Space: O(N)

We could maintain a lexicographical order stack whiling looping through the string. If we encounter a new pending character which is not visited before and greater than the
top of stack, we could greedily push it to the stack. Otherwise, we need to pop the elements out of stack as long as the overall storage of this element is still not empty until either the top element in the stack is not greater than the pending element or the storage of top element in the stack is empty. Furthermore, if we encoutner a pending element which has been visited before, we don't want to remove the elements inside the stack to compensate the action of pushing this element to the stack, since it would not result in a better lexicographical order elements inside the stack in the future.
