# 721. Accounts Merge

###### Tag: Union Find, Hash Table

For each group of accounts, we can sort the emails based on their size. Since the 1st email has the shortest length, this could be trated as the root email for the rest of the emails. We then `Union` the rest of emails with the root email for each group. Remember to assign the owner name to each of the email. After that, we use `Find` to update the root email of all the available emails since the previous `Union` operation does not guarantee the "root email" of each emails is at the very low level.    