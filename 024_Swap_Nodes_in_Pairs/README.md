024 Swap Nodes in Pairs
===
`Linked List` `Recursion`
# Explanation
* swap every adjacent nodes.

# Approach 1: Recursive Approach
* for each recursive step, swap the first two nodes.
* return the second node as the new head.

## Complexity
* Time: $O(N)$.
* Space: $O(N)$, for recursion stack.

# Approach 2: Iterative Approach
* `head` refers to the current swap operation.
* `pre` refers to second node.
* assign `pre` to the next head.

## Complexity
* Time: $O(N)$.
* Space: $O(1)$.
