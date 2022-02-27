# 662. Maximum Width of Binary Tree

###### Tag: BFS

We can assign order number to the nodes on the same level to calculate the width. The assignment method shows below:

```
int ref = q.front()->val; //use the first element in the current depth as a reference
node->left->val = (node->val - ref) * 2 + 1;
node->right->val = (node->val - ref) * 2 + 2;
```