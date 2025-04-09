## Problem 12.1-1:
(Attached in the assignment on paper)

## Problem 12.1-5:

To build a BST using a list it would take Ω(n lg n). This is because the cost to insert 
takes Ω(n lg n) based on the number of key comparisons performed for however many n elements.
But if the list is already sorted it would cost O(n) and then the total cost would be O(n^2).
However, there is no comparison based algorithm tha can sort n elements faster than Ω(n lg n).
So the worst case will always be Ω(n lg n).


## Problem 12.2-2:

### Minimum Recursion Tree (x): 

if x.left ≠ Null

	return tree-min-recursive (x.left)

else: 

	return x


### Maximum Recursion Tree (x):

if x.right ≠ Null

	return tree-max-recursion (x.right)

else: 

	return x

