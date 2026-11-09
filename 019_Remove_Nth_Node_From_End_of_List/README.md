019 Remove Nth Node From End of List
===
`Linked List` `Two Pointers`
# Explanation
* 給定一個 Linked List，刪除從尾部的第 N 個 node。

# Approach 1: Two pass algorithm
* first pass for calculate the list length `L`.
* second pass for removing the `L-n` node. 

## Complexity
* Time: $O(L)$
* Space: $O(1)$

# Approach 2: One pass algorithm
* Using two pointers.
* first pointer for the last visited node.
* second pointer for the `N` node from the first pointer.

## Complexity
* Time: $O(L)$
* Space: $O(1)$

