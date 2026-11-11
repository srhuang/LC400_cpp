021 Merge Two Sorted Lists
===
`Linked List` `Recursion`
# Explanation
* 給定兩個 Sorted Lists 並且進行 merge.

# Approach 1: Recursion
* 選擇值比較小的 list node return.
* recusively call function, the return list node become the next node.

## Complexity
* Time: $O(n+m)$.
* Space: $O(n+m)$.

# Approach 2: Iteration
* create local list node `head`.
* choose the smaller list node between `l1` and `l2` become the next node.
* move forward the pointer `l1` or `l2`.
* return `head.next`.

## Complexity
* Time: $O(n+m)$.
* Space: $O(1)$.
