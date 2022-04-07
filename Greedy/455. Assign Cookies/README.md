# 455. Assign Cookies
###### Tag: Greedy, Sorting, Two Pointer

###### Time: O(Nlog(N))
###### Space: O(1) 


The optimal way is to assign small cookie to children who have smaller consent and assign large cookie to children
who have larger consent. We need to sort both the children consent and cookie size array and then use the two pointer
method to traverse through both of them.