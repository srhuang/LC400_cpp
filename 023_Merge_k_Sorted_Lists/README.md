023 Merge k Sorted Lists
===
`Linked List` `Priority Queue`
# Explanation
* 合併 `k` 個已排序好的 linked lists。

# Approach 1: Brute Force
* 轉成 array 存放所有 linked list。
* 執行 sort。
* 再轉回 linked list。

## Complexity
* Time: $O(N\times \log N)$, for sorting algorithm.
* Space: $O(N)$.

# Approach 2: Compare one by one
* 比較當前所有 head of lists.
* 挑選最小的加入答案 list, 並且將該 head of list 往後移動。
* 直到 head of lists 都指向 null pointer.

## Complexity
* Time: $O(kN)$, each node costs $k-1$ comparison.
* Space: $O(N)$.

# Approach 3: Priority Queue
* 比較當前所有 head of lists.
* 挑選最小的加入答案 list, 並且將該 head of list 往後移動。
* 挑選最小的演算法使用 priority queue.
* 直到 head of lists 都指向 null pointer.

## Complexity
* Time: $O(N\log k)$.
* Space: $O(N)$, the size of priority queue is $O(k)$.

# Approach 4: Merge lists one by one
* 執行 `k` 次 merge two lists 演算法。

## Complexity
* Time: $O(kN)$
* Space: $O(1)$

# Approach 5: Merge with Divide And Conquer
* 第一層 merge 左右兩兩 merge。
* 第二層 將第一層的結果兩兩 merge。
* 觀察第一層 merge index: (0,1) (2,3) ...
* 觀察第二層 merge index: (0,2) (4,6) ...
* 觀察第三層 merge index: (0,4) (8,12) ...

## Complexity
* Time: $O(N\log k)$
* Space: $O(1)$

