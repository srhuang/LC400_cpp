015 3Sum
===
`Array` `Two Pointers`
# Explanation
* 給定一個整數 array，回傳三個值相加等於 0。

# Approach 1: Two Pointers
* Sorting Array.
* 從左到右依序做 two sum 的算法。
* 需要記錄當前的 index，以此為起點做 two sum。
* Two sum 則是使用 two pointers algorithm.

## Complexity
* Time: $O(n^2)$, two sum is $O(n)$.
* Space: $O(\log n)$, for sorting.

# Approach 1: Hashset
* Sorting Array.
* 利用 i and j pointers 當成 window.
* 隨著 window 向右慢慢打開 (j++)，set 裡面的 complement 依序加入。
* 在 window 裡面找尋合適的 complement.

## Complexity
* Time: $O(n^2)$, two sum is $O(n)$.
* Space: $O(n)$ for hash set.


