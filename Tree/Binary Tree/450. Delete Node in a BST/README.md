# 450. Delete Node in a BST

###### Tag: Binary Tree, DFS

This problem aims at deleting a node for a BST. It is difficult to delete such node directly since the deletion might change the whole structure of its left and right subtrees with many edge cases. Once we find out the location of this node, we need to check if its left subtree or right subtree or both of them are null pointer, the benfit of doing so is that we could simply return either left, right subtree or null pointer of this node. If the node structure does not meet the conditions above, we need to find the 1st node which is greater than the deleted node in the deleted node's right subtree, then swap their values, and recursively solve this problem by deleting the target node in the deleted node's right subtree. 
