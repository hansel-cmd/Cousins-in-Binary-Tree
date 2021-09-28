# Cousins-in-Binary-Tree
Finding Cousins in Binary Tree

## Definition
- Two nodes of a binary tree are cousins if they have the same depth with different parents.

- Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1. 
- But in this example, we make depth 0 when given person does not exist in the tree, while depth 1 corresponds to the root node.

```
 given Tree
		             10
	 	          /      \
		          6       14
	                /  \     /   \
	               5    7   12     18
	              /      \    \    /  \
	             1       8   13    15   20
      
 given person = 1
      
      
 expected output: 8 13 15 20
```

G! Try. xd
