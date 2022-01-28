# 763. Partition Labels

###### Tag: String, Hash Table

We can store the information of last seen index for all the characteers. A two pointer method is used to keep track of the current max required interval for a potential partition. We then
loop through the entire string, if the current index of string is the same as the latter pointer, the interval can be partitioned.
