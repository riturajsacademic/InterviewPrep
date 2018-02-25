There are 2 ways of solving it.

1. Do Preorder traversal of the trees.
	Speed:
			O(n1)+O(n)+O(n) // searching for node
	Space:
			O(n1)+O(n)

2. No space implementation
	Idea is to search for the root node of the Tree2. once you get that. 
	do a preorder traversal of the Tree1 and Tree 2 at the same time. 
	Speed:
			O(nlogn)+O(n)