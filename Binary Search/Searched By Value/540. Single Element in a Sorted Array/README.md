# 540. Single Element in a Sorted Array

###### Tag: Bninary Search, Searched by Value

The optimal way to achieve log(n) time would be using binary search to find out the single element. First we need to find out if this single element locates at the first and last location of the array. If so, we can simply return this value; Otherwise, the index of same element would strictly follows the 'even-odd' pattern until a single elemnt breaks this pattern, in other words, the index of same element would alternatively follow 'odd-even' pattern after the inclusion of single element. We can take the advantage of this pattern to use binary search. 
