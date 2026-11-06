016 3Sum Closest
===
`Array` `Two Pointers`
# Explanation
* 給定一個整數 array。
* 在所有三個相加的值中，最靠近 target 的值。

# Approach 1: Binary Search
* Sorting Array.
* 第一個值和第二個值使用窮舉。
* 第三個值使用 binary search 找尋最靠近 target 的值。

## Complexity
* Time: $O(n^2\log n)$
* Space: $O(\log n)$, for sorting.

# Approach 2: Two Pointers
* Sorting Array.
* 從左到右依序做 two pointers 的算法。
* 需要記錄當前的 index `i`，以此為起點 `i+1` 做 two pointers。
* keep tracking the diff between target and sum.

## Complexity
* Time: $O(n^2)$
* Space: $O(\log n)$, for sorting.


